import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JTextArea;

public class SwingNotepad extends JFrame implements ActionListener, KeyListener{
	
	private static final long serialVersionUID = 1L;
	JFrame f1;
	JTextArea t1;
	JMenuBar m;
	JMenu file,edit,format,view,help;
	JMenuItem New,open,save,save_as,exit,print;
	JMenuItem cut,copy,paste,delete,undo,find,find_next,replace,select_all;
	JMenuItem font;
	JMenuItem status;
	JMenuItem about,get_help;
	BorderLayout br;
	
	public SwingNotepad(){

		f1=new JFrame("WritePad");
		f1.setVisible(true);
		f1.setSize(1000,700);
		
		br=new BorderLayout();
		f1.setLayout(br);
		
		t1=new JTextArea();
		t1.requestFocusInWindow();
		f1.add(t1,BorderLayout.CENTER);
		
		m=new JMenuBar();
		
		file=new JMenu("File");
		edit=new JMenu("Edit");
		format=new JMenu("Format");
		view=new JMenu("View");
		help=new JMenu("Help");
		
		New=new JMenuItem("New          CTRL+N");
		open=new JMenuItem("Open        CTRL+O");
		save=new JMenuItem("Save         CTRL+S");
		save_as=new JMenuItem("Save as..");
		print=new JMenuItem("Print        CTRL+P");
		exit=new JMenuItem("Exit");
		
		file.add(New);
		file.add(open);
		file.add(save);
		file.add(save_as);
		file.add(print);
		file.add(exit);
		
		undo=new JMenuItem("Undo             CTRL+Z");
		cut=new JMenuItem("Cut                 CTRL+X");
		copy=new JMenuItem("Copy              CTRL+C");
		paste=new JMenuItem("Paste            CTRL+V");
		delete=new JMenuItem("Delete                    Del");
		find=new JMenuItem("Find               CTRL+F");
		find_next=new JMenuItem("Find Next                F3");
		select_all=new JMenuItem("Select All      CTRL+A");
		replace=new JMenuItem("Replace         CTRL+H");
		
		edit.add(undo);
		edit.add(cut);
		edit.add(paste);
		edit.add(copy);
		edit.add(delete);
		edit.add(find);
		edit.add(find_next);
		edit.add(select_all);
		edit.add(replace);
		
		status=new JMenuItem("Status Bar");
		view.add(status);
		
		font=new JMenuItem("Font");
		format.add(font);
		
		about=new JMenuItem("About Notepad");
		get_help=new JMenuItem("Help");
		help.add(about);
		help.add(get_help);
		
		m.add(file);
		m.add(edit);
		m.add(format);
		m.add(view);
		m.add(help);
		
		f1.setJMenuBar(m);
		
		cut.addActionListener(this);
		copy.addActionListener(this);
		paste.addActionListener(this);
		select_all.addActionListener(this);
		about.addActionListener(this);
		exit.addActionListener(this);
		get_help.addActionListener(this);
		delete.addActionListener(this);
		this.addKeyListener(this);
		
	}
	public static void main(String[] args) {
		new SwingNotepad();
	}
	@Override
	public void actionPerformed(ActionEvent my) {
		// TODO Auto-generated method stub
		if(my.getSource()==cut){
			t1.cut();
		}
		else if(my.getSource()==paste){
			t1.paste();
		}
		else if(my.getSource()==copy){
			t1.copy();
		}
		else if(my.getSource()==get_help){
			t1.setText("For Help Visit:-https://my.WritePad.com");
		}
		else if(my.getSource()==about){
			t1.setText("Author:SWAPNAJIT PATIL.\n"
					+"Version: WritePad v1.3.7(64-Bit)\n"
					+ "This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1.2 of the License, or (at your option) any later version."
					+"\nThanks For Using.\n");
		}
		else if(my.getSource()==select_all){
			t1.selectAll();
		}
		else if(my.getSource()==exit){
			f1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		}
	 }
	@Override
	public void keyPressed(KeyEvent e) {
		// TODO Auto-generated method stub
		 if ((e.getKeyCode() == KeyEvent.VK_C) && ((e.getModifiers() & KeyEvent.CTRL_MASK) != 0)) {
             t1.copy();
         }
		 if ((e.getKeyCode() == KeyEvent.VK_X) && ((e.getModifiers() & KeyEvent.CTRL_MASK) != 0)) {
             t1.cut();
         }
		 if ((e.getKeyCode() == KeyEvent.VK_V) && ((e.getModifiers() & KeyEvent.CTRL_MASK) != 0)) {
             t1.paste();
         }
	}
	@Override
	public void keyReleased(KeyEvent e) {
		// TODO Auto-generated method stub
		
	}
	@Override
	public void keyTyped(KeyEvent e) {
		// TODO Auto-generated method stub
		
	}
}
