import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.util.Scanner;

public class CollectorPanel extends JPanel{
   private JButton use;
   public CollectorPanel(){
      use = new JButton("Use the Agar Collector");
      setLayout(new FlowLayout());
      JLabel m = new JLabel("Agar Collector: ");
      Font f = new Font("Calibri", Font.BOLD, 18);
      m.setFont((f));
      m.setForeground(Color.RED);
      add(m);
      add(use);      
      use.addActionListener(new Listener());
  }
   public class Listener implements ActionListener {
      public Listener(){
         
      }
      
		@Override
		public void actionPerformed(ActionEvent arg0) {
       
      }
	}
}

