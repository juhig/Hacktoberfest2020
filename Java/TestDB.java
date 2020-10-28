import java.sql.ResultSetMetaData;
import java.sql.Statement;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.Scanner;


public class TestDB {
	public static void main(String[] args) {
		Connection con;
		PreparedStatement ps;
		ResultSet rs;
		int ch;
		Scanner sc=new Scanner(System.in);
		try{
			//Class.forName("com.jdbc.mysql.driver");
			Class.forName("oracle.jdbc.OracleDriver");
			//"jdbc:mysql://localhost:3306","root","root
			con=DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:XE","SYSTEM","swapy");
			
			do{
				System.out.println("1.Insert\n2.Delete\n3.Update\n4.View\n0.Exit");
				ch=sc.nextInt();
				switch(ch){
					case 1:
						System.out.println("Enter the ID, Name, Surname of Students");
						ps=con.prepareStatement("insert into MyData values(?,?,?)");
						ps.setInt(1, sc.nextInt());
						ps.setString(2, sc.next());
						ps.setString(3, sc.next());
						int i=ps.executeUpdate();
						if(i>0){
							System.out.println("User Added");
						}
						else{
							System.out.println("Database Access Failed");
						}
						break;
					case 2:
						System.out.println("Enter ID to delete Students");
						ps=con.prepareStatement("delete from MyData where id=?");
						ps.setInt(1, sc.nextInt());
						i=ps.executeUpdate();
						if(i>0){
							System.out.println("Student Delete Successful");
						}
						break;
					case 3:
						System.out.println("1.Update ID\n2.Update Name & Surname");
						int n=sc.nextInt();
						switch(n){
							case 1:
								System.out.println("Enter Name to Update ID");
								String name=sc.next();
								System.out.println("Enter ID to be updated");
								ps=con.prepareStatement("update MyData set id=? where name=?");
								ps.setInt(1, sc.nextInt());
								ps.setString(2, name);
								i=ps.executeUpdate();
								if(i>0){
									System.out.println("ID updated Successfully");
								}
								break;
							case 2:
								System.out.println("Enter ID to update Name");
								int m=sc.nextInt();
								System.out.println("Enter Name&Surname to be updated");
								ps=con.prepareStatement("update MyData set name=?,surname=? where id=?");
								ps.setString(1, sc.next());
								ps.setString(2, sc.next());
								ps.setInt(3, m);
								i=ps.executeUpdate();
								if(i>0){
									System.out.println("Name updated Successfully");
								}
								break;
						}
					case 4:
						String str="select * from MyData";
						Statement st=con.createStatement();
						rs=st.executeQuery(str);
						ResultSetMetaData rsmd=rs.getMetaData();
						for(i=1;i<=rsmd.getColumnCount();i++){
							System.out.print(rsmd.getColumnName(i)+"\t");
							
						}
						System.out.println();
						while(rs.next()){
							System.out.println(rs.getInt(1)+"\t"+rs.getString(2)+"\t"+rs.getString(3));
						}
				}
			}while(ch!=0);
			
		}
		catch(ClassNotFoundException e){
			System.out.println("Exception 1");
		}
		catch(SQLException e){
			System.out.println("Exception 2");
		}
	}
}