SET TIMEZONE UTC
SELECT CAST("1970-01-01T000001.000" as datetime) - "1970-01-01" AS intv
SELECT CAST("1970-01-01T000001.000" as datetime) - "invalid_date" AS intv
