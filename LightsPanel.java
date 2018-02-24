import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.util.Scanner;

public class LightsPanel extends JPanel{
   private JButton brighten, darken;
   int val;
   private JLabel currentVal;
   Scanner infile = null;
   public LightsPanel(){
            try{
         infile = new Scanner(new File("lights"));
      }catch(FileNotFoundException e){
         System.err.println("File not found!");
         System.exit(0);
      } 
      val = Integer.parseInt(infile.next());
      brighten = new JButton("Brighten the Lights 10%");
		darken = new JButton("Darken the Lights 10%");
      setLayout(new FlowLayout());
		JPanel subpanel = new JPanel();
		subpanel.setLayout(new GridLayout(1,3));
      JLabel m = new JLabel("Lights: ");
      Font f = new Font("Calibri", Font.BOLD, 18);
      m.setFont((f));
      m.setForeground(Color.RED);
      add(m);
      JPanel buttons = new JPanel(new GridLayout(2,1));
      buttons.add(brighten);
      buttons.add(darken);
      add(buttons);
      currentVal = new JLabel(""+val);
      currentVal.setFont(f);
      add(currentVal);
      
      brighten.addActionListener(new Listener(true));
      darken.addActionListener(new Listener(false));
      

    


}
   public class Listener implements ActionListener {
      boolean b;
      public Listener(boolean b){
         b=b;
      }
      
		@Override
		public void actionPerformed(ActionEvent arg0) {
         
         if(b){
            if(val==100){
               return;
            }else{
               val+=10;
            }
            
         }else{
            if(val==0){
               return;
            }else{
               val-=10;
            }
         } 
         try{
           System.setOut(new PrintStream(new FileOutputStream("lights")));
         }catch(FileNotFoundException e){
            System.err.println("File not found!");
            System.exit(0);
         } 
  		   System.out.println(val);
         currentVal.setText(""+val);
      }
	}
}

