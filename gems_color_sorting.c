
			//**********gems color sorting program**************
#include"highgui.h"
#include"cv.h"
#include"stdio.h"
int r=0,g=0,b=0,y=0,o=0;
int main( int argc, char** argv ) 

{
	int l;			//for number of inputs
	printf("\n*******WELCOME TO GEMS COLOR SORTING**************\n");

	for(l=1;l<argc;l++)
	{
		IplImage *src = cvLoadImage( argv[l]);

		IplImage *copy = cvCreateImage(cvGetSize(src),8,3); //Create a new image of,8 bit,3 channel


		CvScalar s,c; // create two scalar variables

		int i,j;
		printf("\n**********Frame loaded*************\n");
		cvNamedWindow("Input",10);
		cvNamedWindow("Output",10);

		int red=0,green=0,yellow=0,blue=0,orange=0;
		for(i=0;i<(src->height);i++)		
		{
			for(j=0;j<(src->width);j++)
			{
				s=cvGet2D(src,i,j); 
// if RGB values (in the order as in code) are satisfying threshold condn ie. RED<50 & GREEN>100 & BLUE<100
				if((s.val[2]<50)&&(s.val[1]>75)&&(s.val[0]<100))		//green
				{
					green++;
				}
				else if((s.val[2]>100)&&(s.val[1]<50)&&(s.val[0]<50))		//red
				{
					red++;
				}
				else if((s.val[2]>100)&&(s.val[1]>125)&&(s.val[0]<40))		//yellow
				{
					yellow++;
				}
				else if((s.val[2]<50)&&(s.val[1]<150)&&(s.val[0]>50))		//blue
				{
					blue++;
				}
				else if((s.val[2]>180)&&(s.val[1]<125)&&(s.val[0]<30))		//orange
				{
					orange++;
				}
				else //Set all other pixels in copy to white
				{
					c.val[2]=255;		 
					c.val[1]=255;		
					c.val[0]=255;		
					cvSet2D(copy,i,j,c); 
				}
			}
		}
		printf("\n___________GEMS COLOR FOUND__________\n");

		printf("y=%d\ng=%d\nr=%d\no=%d\nb=%d\n",yellow,green,red,orange,blue);

		if((green>red)&&(green>yellow)&&(green>blue)&&(green>orange))
		{
			printf("\n============>GREEN GEMS\n");
			g++;
		}
		else if((red>green)&&(red>yellow)&&(red>blue)&&(red>orange))
		{
			printf("\n============>RED GEMS\n");
			r++;
		}
		else if((yellow>green)&&(yellow>red)&&(yellow>blue)&&(yellow>orange))
		{
			printf("\n============>YELLOW GEMS\n");
			y++;
		}
		else if((blue>green)&&(blue>red)&&(blue>yellow)&&(blue>orange))
		{
			printf("\n============>BLUE GEMS\n");
			b++;
		}
		else if((orange>green)&&(orange>red)&&(orange>yellow)&&(orange>blue))
		{
			printf("\n============>ORANGE GEMS\n");
			o++;
		}
		else
			printf("Sorry,cant able to find!!!!!!");
	
		cvNamedWindow( "Input", 10 ); //Create a window “Input”
		cvShowImage( "Input", src ); //Display src in a window named “Input”
		cvNamedWindow( "Output", 10 ); //Create a window “Output”
		cvShowImage( "Output", copy ); //Display copy in a window named “Output”
		cvWaitKey(0); //Wait till the user presses a key or cvWaitKey(10) will wait for 10ms
		cvReleaseImage( &src );
	        cvDestroyWindow("Input");
		cvDestroyWindow("Output");
	}
		printf("\n*********NUMBER OF COUNTS**********\n");
		printf("\n------TOTAL NUMBER OF RED GEMS   =%d\n",r);
		printf("\n------TOTAL NUMBER OF GREEN GEMS =%d\n",g);
		printf("\n------TOTAL NUMBER OF YELLOW GEMS=%d\n",y);
		printf("\n------TOTAL NUMBER OF BLUE GEMS  =%d\n",b);
		printf("\n------TOTAL NUMBER OF ORANGE GEMS=%d\n",o);
		return 0;
}

