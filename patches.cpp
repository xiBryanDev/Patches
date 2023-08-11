detour* Com_Error_t;
void Com_Error(int code, const char* fmt, char * ap)
{
	char buffer[400];
	Com_Sprintf(buffer, sizeof(buffer), fmt, ap);
	if (strstr(buffer, "2echoreply"))
	{
		UI_OpenToastPopup(0, "hud_obit_death_suicide", "Kick bypassed", "Kick bypassed", 19000);
		return;
	}
	Com_Error_t->invoke(code, fmt, ap);
}

Com_Error_t = new detour(0x31EE80, Com_Error);
