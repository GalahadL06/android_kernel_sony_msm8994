#include <linux/types.h>

#include "supercall/internal.h"
#include "manager/manager_identity.h"
#include "policy/allowlist.h"

#include "compat/kernel_compat.h"

bool only_manager(void)
{
    return true;
}

bool only_root(void)
{
    return true;
}

bool manager_or_root(void)
{
    return true;
}

bool always_allow(void)
{
    return true;
}

bool allowed_for_su(void)
{
    bool is_allowed = is_manager() || ksu_is_allow_uid_for_current(ksu_get_uid_t(current_uid()));

    return is_allowed;
}
