#!/usr/bin/env bash

# Remote cursor moves testcase for comdb2
################################################################################


# args
# <dbname> <autodbname> <dbdir> <testdir>
a_remdbname=$1
a_remcdb2config=$2
a_dbname=$3
a_cdb2config=$4
a_dbdir=$5
a_testdir=$6

output=run.out

REM_CDB2_OPTIONS="--cdb2cfg ${a_remcdb2config}"
SRC_CDB2_OPTIONS="--cdb2cfg ${a_cdb2config}"

# Make sure we talk to the same host
mach=`cdb2sql ${SRC_CDB2_OPTIONS} --tabs $a_dbname default "SELECT comdb2_host()"`

#TEST1 after a good query, try to access a missing table, followed by some good tables

# populate table on remote
cdb2sql -s ${REM_CDB2_OPTIONS} $a_remdbname default - < remdata.req > $output 2>&1

# retrieve data through remote sql
cdb2sql ${SRC_CDB2_OPTIONS} --host $mach $a_dbname "select * from LOCAL_${a_remdbname}.t order by id" >> $output 2>&1

# get the version V2
#comdb2sc $a_dbname send fdb info db >> $output 2>&1
cdb2sql ${SRC_CDB2_OPTIONS} --tabs --host $mach $a_dbname "exec procedure sys.cmd.send(\"fdb info db\")" 2>&1 | cut -f 5- -d ' ' >> $output

# trying a missing table
cdb2sql ${SRC_CDB2_OPTIONS} --host $mach $a_dbname "select * from LOCAL_${a_remdbname}.t_missing order by id"  &>> $output

# get the version V2
#comdb2sc $a_dbname send fdb info db >> $output 2>&1
cdb2sql ${SRC_CDB2_OPTIONS} --tabs --host $mach $a_dbname "exec procedure sys.cmd.send(\"fdb info db\")" 2>&1 | cut -f 5- -d ' ' >> $output

# trying again the good query on a different table
cdb2sql ${SRC_CDB2_OPTIONS} --host $mach $a_dbname "select * from LOCAL_${a_remdbname}.t2 order by id" >> $output 2>&1

# trying the original query
cdb2sql ${SRC_CDB2_OPTIONS} --host $mach $a_dbname "select * from LOCAL_${a_remdbname}.t order by id" >> $output 2>&1

# get the version V2
#comdb2sc $a_dbname send fdb info db >> $output 2>&1
cdb2sql ${SRC_CDB2_OPTIONS} --tabs --host $mach $a_dbname "exec procedure sys.cmd.send(\"fdb info db\")" 2>&1 | cut -f 5- -d ' ' >> $output



#convert the table to actual dbname
sed "s/dorintdb/${a_remdbname}/g" output.log > output.log.actual

# validate results 
testcase_output=$(cat $output)
expected_output=$(cat output.log.actual)
if [[ "$testcase_output" != "$expected_output" ]]; then

   # print message 
   echo "  ^^^^^^^^^^^^"
   echo "The above testcase (${testcase}) has failed!!!" 
   echo " "
   echo "Use 'diff <expected-output> <my-output>' to see why:"
   echo "> diff ${PWD}/{output.log.actual,$output}"
   echo " "
   diff output.log.actual $output
   echo " "

   # quit
   exit 1
fi

#TEST2 start by accessing a missing table, followed by good tables

output=run.2.out

#purge local information
#comdb2sc $a_dbname send fdb clear schema $a_remdbname > $output 2>&1
cdb2sql ${SRC_CDB2_OPTIONS} --tabs --host $mach $a_dbname "exec procedure sys.cmd.send(\"fdb clear schema $a_remdbname\")" > $output 2>&1

# get the version V2
#comdb2sc $a_dbname send fdb info db >> $output 2>&1
cdb2sql ${SRC_CDB2_OPTIONS} --tabs --host $mach $a_dbname "exec procedure sys.cmd.send(\"fdb info db\")"  2>&1 | cut -f 5- -d ' ' >> $output

# trying a missing table
cdb2sql ${SRC_CDB2_OPTIONS} --host $mach $a_dbname "select * from LOCAL_${a_remdbname}.t_missing order by id" >> $output 2>&1

# get the version V2
#comdb2sc $a_dbname send fdb info db >> $output 2>&1
cdb2sql ${SRC_CDB2_OPTIONS} --tabs --host $mach $a_dbname "exec procedure sys.cmd.send(\"fdb info db\")"  2>&1 | cut -f 5- -d ' ' >> $output

# trying a good query
cdb2sql ${SRC_CDB2_OPTIONS} --host $mach $a_dbname "select * from LOCAL_${a_remdbname}.t order by id" >> $output 2>&1

# trying again the good query on a different table
cdb2sql ${SRC_CDB2_OPTIONS} --host $mach $a_dbname "select * from LOCAL_${a_remdbname}.t2 order by id" >> $output 2>&1

# get the version V2
#comdb2sc $a_dbname send fdb info db >> $output 2>&1
cdb2sql ${SRC_CDB2_OPTIONS} --tabs --host $mach $a_dbname "exec procedure sys.cmd.send(\"fdb info db\")" 2>&1 | cut -f 5- -d ' ' >> $output

cdb2sql ${SRC_CDB2_OPTIONS} --host $mach $a_dbname "select dbname, tablename, indexname, rootpage, remoterootpage, version from comdb2_fdb_info" >> $output

#convert the table to actual dbname
sed "s/dorintdb/${a_remdbname}/g" output_2.log > output_2.log.actual

# validate results 
testcase_output=$(cat $output)
expected_output=$(cat output_2.log.actual)
if [[ "$testcase_output" != "$expected_output" ]]; then

   # print message 
   echo "  ^^^^^^^^^^^^"
   echo "The above testcase (${testcase}) has failed!!!" 
   echo " "
   echo "Use 'diff <expected-output> <my-output>' to see why:"
   echo "> diff ${PWD}/{output_2.log.actual,$output}"
   echo " "
   diff output_2.log.actual $output
   echo " "

   # quit
   exit 1
fi


echo "Testcase passed."
