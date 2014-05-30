
#include <stdio.h>
#include "libwlmessage.h"


int main (int argc, char *argv[])
{
	struct wlmessage *wlmessage = wlmessage_create ();

	wlmessage_set_title (wlmessage, "MyTitle");
	wlmessage_set_titlebuttons (wlmessage, WLMESSAGE_TITLEBUTTON_MINIMIZE
	                                     | WLMESSAGE_TITLEBUTTON_CLOSE);
	wlmessage_set_noresize (wlmessage, 1);
	wlmessage_set_icon (wlmessage, "/usr/share/pixmaps/debian-logo.png");
	wlmessage_set_message (wlmessage, "MyMessage");
	wlmessage_set_textfield (wlmessage, "MyText");
	wlmessage_add_button (wlmessage, 1, "Ok");
	wlmessage_add_button (wlmessage, 0, "Cancel");
	wlmessage_set_default_button (wlmessage, 0);

	int result;
	result = wlmessage_show (wlmessage, NULL);

	wlmessage_destroy (wlmessage);


	return 0;
}
