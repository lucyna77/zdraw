#include <include/global.hpp>

//int __stdcall wWinMain( HINSTANCE instance_handle, HINSTANCE, PWSTR, int )
int main( )
{
	if ( !render::initialize( ) )
    {
		printf( "Failed to initialize render system.\n" );
        return -1;
    }

	render::loop( );

    return 0;
}