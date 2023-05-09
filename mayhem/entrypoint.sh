#!/bin/bash

export PATH=$PATH:/comdb2/bb/bin

pmux -n
comdb2 $DB_NAME &
sleep 2
exec cdb2sql $DB_NAME -f /input
