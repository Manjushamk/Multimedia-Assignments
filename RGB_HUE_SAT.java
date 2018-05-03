package image_RGB_HUE_SAT;

/* importing packages libraries */

import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.io.*;


public class RGB_HUE_SAT {

	public static void main(String[] args) {

		// initiate buffer for the original image to null
		BufferedImage org_image = null;

		//try catch block to catch exception if file reading returns error
		try
		{
			// reading the original error message from the file
			org_image=ImageIO.read(new File("image.png"));
		}

		catch(Exception e)
		{ 
			System.out.println("Error for file reading");
			e.printStackTrace(); // To print the error message
		}

		// Calculating height and width of the 
		int height=org_image.getHeight();
		int width=org_image.getWidth();

		int[][] image_to_array = new int[height*width][3];
		double[][] image_to_hsv=new double[height*width][3];

		int colors[]=new int[3];
		int flag = 0;
		for(int j = 0; j < height; j++)
		{
			//assigning the RGB to the matrix from the original image
			for(int i = 0; i < width; i++)
			{
				int rgb_holder = org_image.getRGB(i,j);

				colors[0]=(rgb_holder>>16)&0xff;
				colors[1]=(rgb_holder >> 8)&0xff;
				colors[2]=(rgb_holder) & 0xff; 
				for(int k = 0; k < 3; k++)
				{
					image_to_array[flag][k] = colors[k];
				}
				flag++;
			}
		}

		//calculation of hue and saturation using the formulae

		int max_val ,min_val;
		double h,s,v;
		int red,green,blue,difference;
		for(int i=0;i<(height*width);i++)
		{

			red=image_to_array[i][0];
			green=image_to_array[i][1];
			blue=image_to_array[i][2];

			//calculation of minimum and maximum of RGB values

			max_val =Math.max(Math.max(red,green),blue);
			min_val =Math.min(Math.min(red,green),blue);

			difference = max_val - min_val;
			int lightness = red + green + blue;
			v = max_val; // brightness value for the hue and saturation

			if( max_val > 0 )
			{
				//calculation of saturation from formula given in slides
				s = 1 - ((3*min_val) /lightness) ;
				h = -1;
			}
			else 
			{
				s = 0;
				h = -1;
			}
			if(difference >0)
			{
				// calculation of hue value from formula given in slides
				h = ((red-green)+(red-blue))/Math.sqrt(((red-green)*(red-green)) + ((red-blue)*(green-blue)));

			}

			if (difference < 0)
			{
				s=-1;
				h=-1;
			}
			// assigning hue saturation values

			image_to_hsv[i][0]=h;
			image_to_hsv[i][1]=s;
			image_to_hsv[i][2]=v;

		}

		// converting the hsv to modified_imagenary image format

		int imag_mod3[]=new int[height*width];
		BufferedImage modified_image = new BufferedImage(width, height, BufferedImage.TYPE_INT_RGB);
		for(int j = 0 ; j < height*width ; j++)
		{
			for(int i = 0; i <3 ; i++)
			{
				int scale = (int) image_to_hsv[j][i] & 0xff;
				int red_scale=(scale << 16);
				int blue_scale= (scale << 8); 
				int green_scale= scale;
				int RGBval = ((red_scale) + blue_scale + green_scale);
				imag_mod3[j]= RGBval;
			}

		}
		int flag1=0;

		// setting the RGB values for output image
		for(int i = 0; i < height ; i++){
			for(int j = 0; j < width ; j++){
				modified_image.setRGB(j,i,imag_mod3[flag1]);
				flag1++;

			}}

		// converting the HSV to modified_imagenary image format

		int imag_mod4[]=new int[height*width];
		BufferedImage modified_image1 = new BufferedImage(width, height, BufferedImage.TYPE_INT_RGB);
		for(int j = 0; j < height*width ; j++){
			for(int i = 0 ; i <3 ; i++){
				int scale = (int) image_to_hsv[j][i] & 0xff;
				int red_scale=(scale << 16);int blue_scale= (scale << 8); int green_scale= scale;
				int RGBval = ((red_scale - 10) + (blue_scale/2) + (green_scale/2));
				imag_mod4[j]= RGBval;
			}

		}

		//setting the RGB values for the output image

		int flag2=0;
		for(int i = 0; i < height; i++){
			for(int j = 0; j < width ; j++){
				modified_image1.setRGB(j,i,imag_mod4[flag2]);
				flag2++;

			}}


		// try catch to capture error while outputting the resultant images
		try
		{
			ImageIO.write(modified_image, "PNG", new File("output_file"));
			ImageIO.write(modified_image1, "PNG", new File("output_file2"));
		}

		catch(Exception e)
		{
			System.out.println("Error if the output files are not generated successfully");
			e.printStackTrace();
		}


	}
}