/* Copyright © 2014 Manuel Bachmann */

#ifndef _WLMESSAGE_H_
#define _WLMESSAGE_H_

#ifndef EXPORT_API
#define EXPORT_API
#endif // EXPORT_API


struct wlmessage;

enum wlmessage_titlebutton {
	WLMESSAGE_TITLEBUTTON_NONE,
	WLMESSAGE_TITLEBUTTON_MINIMIZE,
	WLMESSAGE_TITLEBUTTON_MAXIMIZE,
	WLMESSAGE_TITLEBUTTON_CLOSE,
	WLMESSAGE_TITLEBUTTON_ALL
};

EXPORT_API void
wlmessage_set_title (struct wlmessage *wlmessage, char *title);

EXPORT_API char *
wlmessage_get_title (struct wlmessage *wlmessage);

EXPORT_API void
wlmessage_set_titlebuttons (struct wlmessage *wlmessage, enum wlmessage_titlebutton titlebuttons);

EXPORT_API enum wlmessage_titlebutton
wlmessage_get_titlebuttons (struct wlmessage *wlmessage);

EXPORT_API void
wlmessage_set_noresize (struct wlmessage *wlmessage, unsigned int not_resizable);

EXPORT_API unsigned int
wlmessage_get_noresize (struct wlmessage *wlmessage);

EXPORT_API void
wlmessage_set_icon (struct wlmessage *wlmessage, char *icon_path);

EXPORT_API void
wlmessage_set_message (struct wlmessage *wlmessage, char *message);

EXPORT_API char *
wlmessage_get_message (struct wlmessage *wlmessage);

EXPORT_API void
wlmessage_set_message_file (struct wlmessage *wlmessage, char *file_path);

EXPORT_API void
wlmessage_add_button (struct wlmessage *wlmessage, unsigned int index, char *caption);

EXPORT_API void
wlmessage_delete_button (struct wlmessage *wlmessage, unsigned int index);

EXPORT_API void
wlmessage_set_default_button (struct wlmessage *wlmessage, unsigned int index);

EXPORT_API void
wlmessage_set_textfield (struct wlmessage *wlmessage, char *default_text);

EXPORT_API char *
wlmessage_get_textfield (struct wlmessage *wlmessage);

EXPORT_API void
wlmessage_set_progress_callback (struct wlmessage *wlmessage, void (*callback) (struct wlmessage *wlmessage, void *data), void *data);

EXPORT_API void
wlmessage_set_progress (struct wlmessage *wlmessage, float progress);

EXPORT_API float
wlmessage_get_progress (struct wlmessage *wlmessage);

EXPORT_API void
wlmessage_set_timeout (struct wlmessage *wlmessage, unsigned int timeout);

EXPORT_API unsigned int
wlmessage_get_timeout (struct wlmessage *wlmessage);

EXPORT_API int
wlmessage_show (struct wlmessage *wlmessage, char **input_text);

EXPORT_API struct wlmessage *
wlmessage_create ();

EXPORT_API void
wlmessage_destroy (struct wlmessage *wlmessage);

#endif
