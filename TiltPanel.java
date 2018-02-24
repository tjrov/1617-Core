import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.awt.image.*;
import java.awt.Component.*;
import java.io.*;
import java.util.Scanner;

public class TiltPanel extends JPanel{
   private static final Color BACKGROUND = Color.BLUE;
	private static final int x = 400;
	private static final int y = 400;
	private BufferedImage myImage;
	private Graphics g;
	private TiltSymbol ts;
   int tilt;
   Scanner infile;
   public TiltPanel(){
   		try{
            infile = new Scanner(new File("tilt"));
         }catch(FileNotFoundException e){
            System.exit(0);
         }
         tilt = infile.nextInt();
         myImage = new BufferedImage(x,y,BufferedImage.TYPE_INT_RGB);
   	   g = myImage.getGraphics();		
   		
   		g.setColor(BACKGROUND);
   		g.fillRect(0, 0, x, y);
   		ts = new TiltSymbol(x,tilt);
   		ts.draw(g);
         Timer t = new Timer(3, new Listener());
   		
   	}
      
      public void paintComponent(Graphics g)
      {
        g.drawImage(myImage, 0, 0, x, y, null);
       }
       
      public class Listener implements ActionListener {

		   @Override
		   public void actionPerformed(ActionEvent arg0) {
             try{infile = new Scanner(new File("tilt"));}catch(FileNotFoundException e){
               System.exit(0);
             }
             tilt = infile.nextInt();
             ts.setTilt(tilt);
             ts.setCoordinates();
             ts.draw(g);
             
             repaint();
          }
      }
   
   
}
