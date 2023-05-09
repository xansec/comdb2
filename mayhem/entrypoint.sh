#!/bin/bash

export PATH=$PATH:/comdb2/bb/bin

DB_NAME=fuzzdb

pmux
comdb2 --create $DB_NAME
cp /comdb2/bb/var/cdb2/$DB_NAME/*.dta /testsuite
cp /comdb2/bb/var/cdb2/$DB_NAME/*.lrl /testsuite
comdb2 $DB_NAME & disown
