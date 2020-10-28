package eventHandling_Swing;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JTextField;
import javax.swing.JButton;
import java.awt.Font;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class Calc2 {

	private JFrame frame;
	private JTextField textField;
	
	double num1,num2;
	String operation,answer;
	double result ;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Calc2 window = new Calc2();
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 */
	public Calc2() {
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frame = new JFrame();
		frame.setBounds(100, 100, 300, 472);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(null);
		
		textField = new JTextField();
		textField.setFont(new Font("Tahoma", Font.BOLD, 18));
		textField.setBounds(12, 13, 256, 65);
		frame.getContentPane().add(textField);
		textField.setColumns(10);
		
		JButton btnbackspace = new JButton("\uF0E7");
		btnbackspace.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				
				String backspace = null;
				if(textField.getText().length() >0) {
					StringBuilder str = new StringBuilder(textField.getText());
					str.deleteCharAt(textField.getText().length()-1);
					backspace = str.toString();
					textField.setText(backspace);
				}
			}
		});
		btnbackspace.setFont(new Font("wingdings", Font.BOLD, 18));
		btnbackspace.setBounds(12, 91, 55, 55);
		frame.getContentPane().add(btnbackspace);
		
		JButton btn7 = new JButton("7");
		btn7.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String num = textField.getText() + btn7.getText();
				textField.setText(num);
			}
		});
		btn7.setFont(new Font("Tahoma", Font.BOLD, 18));
		btn7.setBounds(12, 159, 55, 55);
		frame.getContentPane().add(btn7);
		
		JButton btn4 = new JButton("4");
		btn4.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String num = textField.getText() + btn4.getText();
				textField.setText(num);
			}
		});
		btn4.setFont(new Font("Tahoma", Font.BOLD, 18));
		btn4.setBounds(12, 227, 55, 55);
		frame.getContentPane().add(btn4);
		
		JButton btn1 = new JButton("1");
		btn1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String num = textField.getText() + btn1.getText();
				textField.setText(num);
			}
		});
		btn1.setFont(new Font("Tahoma", Font.BOLD, 18));
		btn1.setBounds(12, 295, 55, 55);
		frame.getContentPane().add(btn1);
		
		JButton btn0 = new JButton("0");
		btn0.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String num = textField.getText() + btn0.getText();
				textField.setText(num);
			}
		});
		btn0.setFont(new Font("Tahoma", Font.BOLD, 18));
		btn0.setBounds(12, 363, 55, 55);
		frame.getContentPane().add(btn0);
		
		JButton btnclear = new JButton("C");
		btnclear.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				textField.setText(null);
			}
		});
		btnclear.setFont(new Font("Tahoma", Font.BOLD, 18));
		btnclear.setBounds(79, 91, 55, 55);
		frame.getContentPane().add(btnclear);
		
		JButton btn8 = new JButton("8");
		btn8.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String num = textField.getText() + btn8.getText();
				textField.setText(num);
			}
		});
		btn8.setFont(new Font("Tahoma", Font.BOLD, 18));
		btn8.setBounds(79, 159, 55, 55);
		frame.getContentPane().add(btn8);
		
		JButton btn5 = new JButton("5");
		btn5.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String num = textField.getText() + btn5.getText();
				textField.setText(num);
			}
		});
		btn5.setFont(new Font("Tahoma", Font.BOLD, 18));
		btn5.setBounds(79, 227, 55, 55);
		frame.getContentPane().add(btn5);
		
		JButton btn2 = new JButton("2");
		btn2.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String num = textField.getText() + btn2.getText();
				textField.setText(num);
			}
		});
		btn2.setFont(new Font("Tahoma", Font.BOLD, 18));
		btn2.setBounds(79, 295, 55, 55);
		frame.getContentPane().add(btn2);
		
		JButton btndot = new JButton(".");
		btndot.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String num = textField.getText() + btndot.getText();
				textField.setText(num);
			}
		});
		btndot.setFont(new Font("Tahoma", Font.BOLD, 18));
		btndot.setBounds(79, 363, 55, 55);
		frame.getContentPane().add(btndot);
		
		JButton btn00 = new JButton("00");
		btn00.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String num = textField.getText() + btn00.getText();
				textField.setText(num);
			}
		});
		btn00.setFont(new Font("Tahoma", Font.BOLD, 18));
		btn00.setBounds(146, 91, 60, 60);
		frame.getContentPane().add(btn00);
		
		JButton btn9 = new JButton("9");
		btn9.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String num = textField.getText() + btn9.getText();
				textField.setText(num);
			}
		});
		btn9.setFont(new Font("Tahoma", Font.BOLD, 18));
		btn9.setBounds(146, 159, 55, 55);
		frame.getContentPane().add(btn9);
		
		JButton btn6 = new JButton("6");
		btn6.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String num = textField.getText() + btn6.getText();
				textField.setText(num);
			}
		});
		btn6.setFont(new Font("Tahoma", Font.BOLD, 18));
		btn6.setBounds(146, 227, 55, 55);
		frame.getContentPane().add(btn6);
		
		JButton btn3 = new JButton("3");
		btn3.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String num = textField.getText() + btn3.getText();
				textField.setText(num);
			}
		});
		btn3.setFont(new Font("Tahoma", Font.BOLD, 18));
		btn3.setBounds(146, 295, 55, 55);
		frame.getContentPane().add(btn3);
		
		JButton btnequal = new JButton("=");
		btnequal.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				
				num2 = Double.parseDouble(textField.getText());
					if(operation.contentEquals("+")) {
						result = num1+num2;
						answer = String.format("%.2f", result);
						textField.setText(answer);
					}
					else if(operation.contentEquals("-")) {
						result = num1-num2;
						answer = String.format("%.2f", result);
						textField.setText(answer);
					}
					else if(operation.contentEquals("*")) {
						result = num1*num2;
						answer = String.format("%.2f", result);
						textField.setText(answer);
					}
					else if(operation.contentEquals("/")) {
						result = num1/num2;
						answer = String.format("%.2f", result);
						textField.setText(answer);
					}
					else if(operation.contentEquals("%")) {
						result = num1%num2;
						answer = String.format("%.2f", result);
						textField.setText(answer);
					}
			}
						
		});
		btnequal.setFont(new Font("Tahoma", Font.BOLD, 18));
		btnequal.setBounds(146, 363, 55, 55);
		frame.getContentPane().add(btnequal);
		
		JButton btnplus = new JButton("+");
		btnplus.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				
				num1  = Double.parseDouble(textField.getText());
				textField.setText("");
				operation = "+";
			}
		});
		btnplus.setFont(new Font("Tahoma", Font.BOLD, 18));
		btnplus.setBounds(213, 91, 55, 55);
		frame.getContentPane().add(btnplus);
		
		JButton btnminus = new JButton("-");
		btnminus.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				num1  = Double.parseDouble(textField.getText());
				textField.setText("");
				operation = "-";
			}
		});
		btnminus.setFont(new Font("Tahoma", Font.BOLD, 18));
		btnminus.setBounds(213, 159, 55, 55);
		frame.getContentPane().add(btnminus);
		
		JButton btnproduct = new JButton("*");
		btnproduct.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				num1  = Double.parseDouble(textField.getText());
				textField.setText("");
				operation = "*";
			}
		});
		btnproduct.setFont(new Font("Tahoma", Font.BOLD, 18));
		btnproduct.setBounds(213, 227, 55, 55);
		frame.getContentPane().add(btnproduct);
		
		JButton btndivide = new JButton("/");
		btndivide.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				num1  = Double.parseDouble(textField.getText());
				textField.setText("");
				operation = "/";
			}
		});
		btndivide.setFont(new Font("Tahoma", Font.BOLD, 18));
		btndivide.setBounds(213, 295, 55, 55);
		frame.getContentPane().add(btndivide);
		
		JButton btnmod = new JButton("%");
		btnmod.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				num1  = Double.parseDouble(textField.getText());
				textField.setText("");
				operation = "%";
			}
		});
		btnmod.setFont(new Font("Tahoma", Font.BOLD, 18));
		btnmod.setBounds(213, 363, 60, 60);
		frame.getContentPane().add(btnmod);
	}

}
