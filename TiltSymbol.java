import java.awt.Color;
import java.awt.Graphics;
import java.lang.*;

public class TiltSymbol {
	
	private Color myColor;
	private int myXwidth;
	private double x1, x2, y1, y2;
	private int tilt;
	
	public TiltSymbol(int myX, int tilt){
		myColor = Color.RED;
		
		myXwidth = myX;
		// myXwidth is the diameter
		
      tilt  = tilt;
	   setCoordinates();
   }
	public double getX1(){
		return x1;	
	}
	public double getY1(){
		return y1;
	}
  	public double getX2(){
		return x2;	
	}
	public double getY2(){
		return y2;
	}
	public int getXWidth(){
		return myXwidth;
	}
	public void setXWidth( int x){
		myXwidth  = x;
	}
   
   public int getTilt(){
      return tilt;
   }
   public void setTilt(int t){
      tilt =t;
      // redraw after every set (use set Coordinates)
   }
	public void draw(Graphics g){
		g.setColor(myColor);
      setCoordinates();
		g.drawLine((int)getX1(), (int)getY1(), (int)getX2(), (int)getY2());
	}
	
	public void setCoordinates(){
     x1 = ((double)myXwidth) * (double)Math.sin(90-tilt); 
     y1 = ((double)myXwidth) * (double)Math.sin(tilt); 
     x2 = x1 * -1;
     y2 = x2*-1;
   }

}