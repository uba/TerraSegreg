#include <terrasegregPluginCode.h>
#include <terrasegregplugin.h>

static TerraSegregPlugin* terrasegregplugin_plg = 0;

// This function will be executed at plugin's loading time.
SPL_PLUGIN_API bool SPL_INIT_NAME_CODE( slcPluginArgs* a_pPluginArgs )
{
	// Extracts plugin parameters
	void* arg_ptrs[ 1 ];

	if( a_pPluginArgs->GetArg( 0, arg_ptrs ) == 0 )
	{
		PluginParameters* params = ( PluginParameters* ) arg_ptrs[ 0 ];

		// Checking the TerraView plugin interface compatibility
		if( params->getVersion() == PLUGINPARAMETERS_VERSION )
		{
			// Loads the plugin translation file
			terrasegregplugin_plg = new TerraSegregPlugin(params);
			terrasegregplugin_plg->init();
		}
	}

	return true;
}

// This function will be executed at plugin's unloading time.
SPL_PLUGIN_API bool SPL_SHUTDOWN_NAME_CODE( slcPluginArgs* a_pPluginArgs )
{
	delete terrasegregplugin_plg;
	terrasegregplugin_plg = 0;

	return true;
}