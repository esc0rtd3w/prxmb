#ifndef __PRXMB_INC__
#define __PRXMB_INC__

#include <stddef.h>

#define prxmb_running() (sys_prx_get_module_id_by_name("PRXMB", 0, NULL) > 0)

/*
 * It is imperative that these settings are in agreement among developers.
 */
#define VSHMODULE_SPRX		"/dev_flash/vsh/module/idle_plugin.sprx"
#define PRXMB_PROXY_SPRX	"/dev_hdd0/tmp/prxmb_proxy.sprx"

#define MAX_ACT_NAMELEN		32

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*action_callback)(const char[MAX_ACT_NAMELEN] /* action name */, const char* /* params */);

/*
 * Hook a function for specified action on proxy plugin.
 * Returns 0 if successfully hooked, or -1 if action was already hooked.
 */
int prxmb_action_hook(const char name[MAX_ACT_NAMELEN], action_callback callback);

/*
 * You should always unhook all your actions when your plugin is unloading.
 */
void prxmb_action_unhook(const char name[MAX_ACT_NAMELEN]);

/*
 * Internally used by proxy plugin to call hooks.
 * The format of module-action should be the action name
 * and parameter data (if necessary) separated by a space.
 */
void prxmb_action_call(const char* action);

#ifdef __cplusplus
}
#endif

#endif
