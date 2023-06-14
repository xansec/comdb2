/* BERK_DEF_ATTR(option, description, type, default) */

BERK_DEF_ATTR(iomap_enabled, "Map file that tells comdb2ar to pause while we fsync", BERK_ATTR_TYPE_BOOLEAN, 1)
BERK_DEF_ATTR(flush_scan_dbs_first, "Don't hold bufpool mutex while opening files for flush", BERK_ATTR_TYPE_BOOLEAN, 0)
BERK_DEF_ATTR(skip_sync_if_direct, "Don't fsync files if directio enabled", BERK_ATTR_TYPE_BOOLEAN, 1)
BERK_DEF_ATTR(warn_on_replicant_log_write, "Warn if replicant is writing to logs", BERK_ATTR_TYPE_BOOLEAN, 1)
BERK_DEF_ATTR(abort_on_replicant_log_write , "Abort if replicant is writing to logs", BERK_ATTR_TYPE_BOOLEAN, 0)
BERK_DEF_ATTR(debug_deadlock_replicant_percent , "Percent of replicant events getting deadlocks", BERK_ATTR_TYPE_PERCENT, 0)
BERK_DEF_ATTR(debug_addrem_dbregs, "Generate debug records for addrems", BERK_ATTR_TYPE_BOOLEAN, 0)
BERK_DEF_ATTR(start_recovery_at_dbregs, "Start recovery at dbregs", BERK_ATTR_TYPE_BOOLEAN, 1)
BERK_DEF_ATTR(apprec_track_lsn_ranges, "During recovery track lsn ranges", BERK_ATTR_TYPE_BOOLEAN, 1)
BERK_DEF_ATTR(dbreg_errors_fatal, "dbreg errors fatal", BERK_ATTR_TYPE_BOOLEAN, 0)
BERK_DEF_ATTR(warn_nondbreg_records, "warn on non-dbreg records before checkpoint", BERK_ATTR_TYPE_BOOLEAN, 0)
BERK_DEF_ATTR(num_write_retries, "number of times to retry writes on ENOSPC", BERK_ATTR_TYPE_INTEGER, 128)
BERK_DEF_ATTR(debug_enospc_chance, "DEBUG %% random ENOSPC on writes", BERK_ATTR_TYPE_PERCENT, 0)
BERK_DEF_ATTR(check_zero_lsn_writes, "Warn on writing pages with zero LSNs", BERK_ATTR_TYPE_BOOLEAN, 1)
BERK_DEF_ATTR(abort_zero_lsn_writes, "Abort on writing pages with zero headers", BERK_ATTR_TYPE_BOOLEAN, 0)
BERK_DEF_ATTR(abort_zero_lsn_memp_put, "Abort on memp_fput pages with zero headers", BERK_ATTR_TYPE_BOOLEAN, 0)
BERK_DEF_ATTR(preallocate_on_writes, "Pre-allocate on writes", BERK_ATTR_TYPE_BOOLEAN, 0)
BERK_DEF_ATTR(preallocate_max, "Pre-allocation size", BERK_ATTR_TYPE_INTEGER, 256 * MEGABYTE)
BERK_DEF_ATTR(lsnerr_pgdump, "Dump page on LSN errors", BERK_ATTR_TYPE_BOOLEAN, 1)
BERK_DEF_ATTR(lsnerr_pgdump_all, "Dump page on LSN errors on all nodes", BERK_ATTR_TYPE_BOOLEAN, 0)
BERK_DEF_ATTR(log_applied_lsns, "Log applied LSNs to log", BERK_ATTR_TYPE_BOOLEAN, 0)
BERK_DEF_ATTR(check_applied_lsns, "Check transaction that its LSNs have been applied", BERK_ATTR_TYPE_BOOLEAN, 0)
BERK_DEF_ATTR(check_applied_lsns_fatal, "Abort if check_applied_lsns fails", BERK_ATTR_TYPE_BOOLEAN, 0)
BERK_DEF_ATTR(check_applied_lsns_debug, "Lots of verbose trace for debugging applied LSNs.", BERK_ATTR_TYPE_BOOLEAN, 0)
BERK_DEF_ATTR(sgio_enabled, "Do scatter gather I/O", BERK_ATTR_TYPE_BOOLEAN, 0)
BERK_DEF_ATTR(sgio_max, "Max scatter gather I/O to do at one time", BERK_ATTR_TYPE_INTEGER, 10 * MEGABYTE)
BERK_DEF_ATTR(btpf_enabled, "Enables index pages read ahead", BERK_ATTR_TYPE_BOOLEAN, 0)
BERK_DEF_ATTR(btpf_wndw_min, "Minimum number of pages read ahead", BERK_ATTR_TYPE_INTEGER, 100 )
BERK_DEF_ATTR(btpf_wndw_max, "Maximum number of pages read ahead", BERK_ATTR_TYPE_INTEGER, 1000 )
BERK_DEF_ATTR(btpf_wndw_inc, "Increment factor for the number of pages read ahead", BERK_ATTR_TYPE_INTEGER, 1)
BERK_DEF_ATTR(btpf_pg_gap, "Min. number of records to the page limit before read ahead", BERK_ATTR_TYPE_INTEGER, 0)
BERK_DEF_ATTR(btpf_cu_gap, "How close a cursor should be (pages) to the prefaulted limit before prefaulting again", BERK_ATTR_TYPE_INTEGER, 5)
BERK_DEF_ATTR(btpf_min_th, "Preload pages only if the tree has heigth less than this parameter", BERK_ATTR_TYPE_INTEGER, 1)
BERK_DEF_ATTR(recovery_verify, "After recovery, run a full pass to make sure everything is applied", BERK_ATTR_TYPE_BOOLEAN, 0)
BERK_DEF_ATTR(recovery_verify_fatal, "Abort if recovery_verify is set, and fails.", BERK_ATTR_TYPE_BOOLEAN, 0)
BERK_DEF_ATTR(cache_lc, "Collect logs into LSN_COLLECTIONs as they come in", BERK_ATTR_TYPE_BOOLEAN, 0)
BERK_DEF_ATTR(cache_lc_max, "Keep this many transactions around in LC cache", BERK_ATTR_TYPE_INTEGER, 16)
BERK_DEF_ATTR(cache_lc_debug, "Lots of verbose messages out of LC cache system", BERK_ATTR_TYPE_BOOLEAN, 0)
BERK_DEF_ATTR(cache_lc_trace_evictions, "Print a message at the point of eviction", BERK_ATTR_TYPE_BOOLEAN, 0)
BERK_DEF_ATTR(cache_lc_trace_misses, "Print a message on cache miss", BERK_ATTR_TYPE_BOOLEAN, 0)
BERK_DEF_ATTR(cache_lc_check, "Check LC cache system on every transaction", BERK_ATTR_TYPE_BOOLEAN, 0)
BERK_DEF_ATTR(cache_lc_memlimit, "Limit total memory used by LC cache (0 = unlimited).", BERK_ATTR_TYPE_INTEGER, 2097152)
BERK_DEF_ATTR(cache_lc_memlimit_tran, "Limit per transaction memory used by LC cache", BERK_ATTR_TYPE_INTEGER, 1048576)
BERK_DEF_ATTR(consolidate_dbreg_ranges, "Combine adjacent dbreg ranges for same file", BERK_ATTR_TYPE_BOOLEAN, 1)
BERK_DEF_ATTR(max_latch, "Size of latch array", BERK_ATTR_TYPE_INTEGER, 200000)
BERK_DEF_ATTR(max_latch_lockerid, "Size of latch lockerid array", BERK_ATTR_TYPE_INTEGER, 10000)
BERK_DEF_ATTR(lockerid_node_step, "Stepup for preallocated lids", BERK_ATTR_TYPE_INTEGER, 128)
BERK_DEF_ATTR(ilock_step, "Stepup for preallocated ilock-latches", BERK_ATTR_TYPE_INTEGER, 2048)
BERK_DEF_ATTR(db_lock_lsn_step, "Stepup for preallocated db_lock_lsns", BERK_ATTR_TYPE_INTEGER, 1024)
BERK_DEF_ATTR(blocking_latches, "Block on latch rather than deadlock", BERK_ATTR_TYPE_BOOLEAN, 0)
BERK_DEF_ATTR(latch_max_wait, "Block at most this many microseconds before returning deadlock", BERK_ATTR_TYPE_INTEGER, 5000)
BERK_DEF_ATTR(latch_poll_us, "Poll latch this many microseconds before retrying", BERK_ATTR_TYPE_INTEGER, 1000)
BERK_DEF_ATTR(latch_max_poll, "Poll latch this many times before returning deadlock", BERK_ATTR_TYPE_INTEGER, 5)
BERK_DEF_ATTR(latch_timed_mutex, "Use a timed mutex", BERK_ATTR_TYPE_BOOLEAN, 1)
BERK_DEF_ATTR(log_cursor_cache, "Cache log cursors", BERK_ATTR_TYPE_BOOLEAN, 0)
BERK_DEF_ATTR(recovery_processor_poll_interval_us, "Recovery processor wakes this often to check workers", BERK_ATTR_TYPE_INTEGER, 1000)
BERK_DEF_ATTR(lsnerr_logflush, "Flush log on lsn error", BERK_ATTR_TYPE_BOOLEAN, 1)
BERK_DEF_ATTR(tracked_locklist_init, "Initial allocation count for tracked locks", BERK_ATTR_TYPE_INTEGER, 10)
/* This is a placeholder for now */
BERK_DEF_ATTR(transient_page_reallocation, "Orphaned pages are maintained locally", BERK_ATTR_TYPE_BOOLEAN, 0)
BERK_DEF_ATTR(elect_highest_committed_gen, "Bias election by the highest generation in the logfile", BERK_ATTR_TYPE_BOOLEAN, 1)
BERK_DEF_ATTR(sync_standalone, "Force a log-sync at commit for standalone instances", BERK_ATTR_TYPE_BOOLEAN, 0)
