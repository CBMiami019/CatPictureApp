/**
* My first app for CSE 274
*/

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class CatPictureAppApp : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();

 private:
	 float red, green, blue;
	 ///These signs will change the direction of the color change (+/-)
	 int redSign, greenSign, blueSign;

};

void CatPictureAppApp::setup()
{
	red = 0.0f;
	green = 0.5f;
	blue = 1.0f;
	redSign = 1;
	greenSign = 1;
	blueSign = 1;
}

void CatPictureAppApp::mouseDown( MouseEvent event )
{
}

void CatPictureAppApp::update()
{

	///I liked what you did in class, but I wanted my color transitions to be smoother
	///So I made the colors bounce between the values of 0.0 - 1.0
	if (red > 1.0f || red < 0.0f) {
		redSign = redSign*-1;
	}
	if (green > 1.0f || green < 0.0f) {
		greenSign = greenSign*-1;
	}
	if (blue > 1.0f || blue < 0.0f) {
		blueSign = blueSign*-1;
	}

	///Regardless of whether _Sign is (+/-) we will add it to the current values
	red = red + (redSign*0.01f);
	green = green + (greenSign*0.01f);
	blue = blue + (blueSign*0.01f);

}

void CatPictureAppApp::draw()
{
	// clear out the window with black
	gl::clear( Color( red, green, blue ) ); 
}

CINDER_APP_BASIC( CatPictureAppApp, RendererGl )
