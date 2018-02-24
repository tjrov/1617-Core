import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.util.Scanner;

public class MotorPanel extends JPanel{
	private JButton forward, backward, up, down; // locking buttons
	private JLabel m1, m2, m3, m4, m5, m6; // motors and their percent efficiencies
   Timer t;	
	public MotorPanel(){
		// what is the specific API we will use to gather data from the joystick and arduino and output it to the api? //
		//for now, one possibility is using a real time update for a file. In this case, all that must be done is that is that the arduino and the 
		// joystick inputs into one file, while the java program reads it
		
		// i have demonstrated this method for the efficiencies for the of the motor
		Scanner infile = null;
      try{
         infile = new Scanner(new File("e"));
      }catch(FileNotFoundException e){
         System.err.println("File not found!");
         System.exit(0);
      } 
		String[] e = new String[6];
		for(int i = 0; i < e.length; i++){
			e[i] = infile.next();
		}
      Font f = new Font("Calibri", Font.ITALIC, 12);
		m1 = new JLabel(e[0]+"%");
      		m2 = new JLabel(e[1]+"%");
		m3 = new JLabel(e[2]+"%");
		m4 = new JLabel(e[3]+"%");
		m5 = new JLabel(e[4]+"%");
		m6 = new JLabel(e[5]+"%");
      m1.setFont(f);
      m2.setFont(f);
      m3.setFont(f);
      m4.setFont(f);
      m5.setFont(f);
      m6.setFont(f);
		forward = new JButton("Lock Forward");
		backward = new JButton("Lock Backward");
		up = new JButton("Lock Up");
		down = new JButton("Lock Down");
		
		setLayout(new FlowLayout());
		JPanel subpanel = new JPanel();
		subpanel.setLayout(new GridLayout(2,1));
		JPanel eff = new JPanel();
		eff.setLayout(new GridLayout(2,6));
		JPanel locks = new JPanel();
		locks.setLayout(new GridLayout(1,4));
		JLabel m = new JLabel("Motors: ");
      m.setFont((new Font("Calibri", Font.BOLD, 18)));
      m.setForeground(Color.RED);
      add(m);
		add(subpanel);
		subpanel.add(eff);
		subpanel.add(locks);
		
		for(int i =1; i <= 6; i++){
			eff.add(new JLabel("Motor "+i));
		}
		eff.add(m1);
		eff.add(m2);
		eff.add(m3);
		eff.add(m4);
		eff.add(m5);
		eff.add(m6);
		
		locks.add(forward);
		locks.add(backward);
		locks.add(up);
		locks.add(down);

		setForeground(Color.GRAY);
		
      t = new Timer(3,new Listener());
		t.start();
	}
	
   public class Listener implements ActionListener {

		@Override
		public void actionPerformed(ActionEvent arg0) {
   		Scanner update = null;
         try{
            update = new Scanner(new File("e"));
         }catch(FileNotFoundException e){
            System.err.println("File not found!");
            System.exit(0);
         } 
         String[] e = new String[6];
   		for(int i = 0; i < e.length; i++){
   			e[i] = update.next();
   		}
         Font f = new Font("Calibri", Font.ITALIC, 12);
   		m1.setText(e[0]+"%");
         m2.setText(e[1]+"%");
   		m3.setText(e[2]+"%");
   		m4.setText(e[3]+"%");
   		m5.setText(e[4]+"%");
   		m6.setText(e[5]+"%");
         for(int z = 0; z < 6; z++){
            if(e[z])
         }
      
      }
	}
}
