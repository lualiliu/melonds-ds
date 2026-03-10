function(apply_git_patches repo_dir patches_dir)
    if (NOT EXISTS "${patches_dir}")
        message(STATUS "No patches dir: ${patches_dir}")
        return()
    endif ()

    file(GLOB patch_files RELATIVE "${patches_dir}" "${patches_dir}/*.patch")
    if (patch_files STREQUAL "")
        message(STATUS "No patch files found in ${patches_dir}")
        return()
    endif ()

    list(SORT patch_files)
    foreach (patch_file IN LISTS patch_files)
        set(patch_path "${patches_dir}/${patch_file}")
        message(STATUS "Applying patch to upstream: ${patch_file}")

        execute_process(
            COMMAND "${GIT_EXECUTABLE}" apply --reverse --check "${patch_path}"
            WORKING_DIRECTORY "${repo_dir}"
            RESULT_VARIABLE reverse_check_rc
            OUTPUT_QUIET
            ERROR_QUIET
        )

        if (reverse_check_rc EQUAL 0)
            message(STATUS "Patch already applied: ${patch_file}")
            continue()
        endif ()

        execute_process(
            COMMAND "${GIT_EXECUTABLE}" apply --whitespace=nowarn "${patch_path}"
            WORKING_DIRECTORY "${repo_dir}"
            RESULT_VARIABLE apply_rc
        )

        if (NOT apply_rc EQUAL 0)
            message(FATAL_ERROR "Failed to apply patch: ${patch_file}")
        endif ()
    endforeach ()
endfunction()

