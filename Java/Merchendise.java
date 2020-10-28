import java.io.*; 
import java.util.*;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

class Inventory
{
	int SmallShirt=4;
	int MedShirt=5;
	int LargeShirt=2;
	int Cap=4;
	public void printInventory()
	{
		System.out.println("INVENTORY--");
		System.out.println("S 	M 	L 	C");
		System.out.println(SmallShirt+" 	"+MedShirt+" 	"+LargeShirt+"	"+Cap);

	}
	
}

public class AlcherMerchendise
{
	
	public static void main(String[] args) throws IOException
	{
		
			
			int sno;
			char item;
			int qun;

			Vector <Integer>sNumber=new Vector<>();
			Vector <Character>itemArray=new Vector<>();
			Vector <Integer>quantity=new Vector<>();

			Inventory q=new Inventory();
			
			ExecutorService ex=Executors.newFixedThreadPool(5);
			q.printInventory();
			File f = new File("test.txt");
			BufferedReader br = new BufferedReader(new FileReader(f)); 
			String line; 
			while ((line = br.readLine()) != null) 
			{
				String[] inputArray=line.split(" ");
				sno=Integer.parseInt(inputArray[0]);
				qun=Integer.parseInt(inputArray[2]);
				item=inputArray[1].charAt(0); 
				sNumber.add(sno);
				itemArray.add(item);
				quantity.add(qun);
		 	} 
		 	int i=0;
			while(i!=itemArray.size())
			{	
				sno=sNumber.get(i);
				item=itemArray.get(i);
				qun=quantity.get(i);
				
				Runnable t= new ReadThread(q,sno,item,qun);
				ex.execute(t);
				i++;
			}
			ex.shutdown();		
	}
}
class ReadThread implements Runnable 
{ 
	private int sno;
	private char item;
	private int qun;
	private Inventory q;
	ReadThread(Inventory q,int sno,char item,int qun) 
	{ 
		this.q=q;
		this.sno = sno; 
		this.item = item; 
		this.qun = qun; 
	} 
	
	public void run() 
	{

		if(item=='S')
		{
			synchronized(q)
			{
				if(q.SmallShirt>=qun)
				{
					System.out.println("Order"+sno+" successfull");
					q.SmallShirt=q.SmallShirt-qun;
					q.printInventory();
				}
				else
				{
				
					System.out.println("Order"+sno+" failed");
					q.printInventory();
				}
			}
		}
		else if(item=='M')
		{
			synchronized(q)
			{
				if(q.MedShirt>=qun)
				{
					System.out.println("Order"+sno+" successfull");
					q.MedShirt=q.MedShirt-qun;
					q.printInventory();
				}	
				else
				{
				
					System.out.println("Order"+sno+" failed");
					q.printInventory();
				}
			}
		}
		else if(item=='L')
		{
			synchronized(q)
			{
				if(q.LargeShirt>=qun)
				{
					System.out.println("Order"+sno+" successfull");
					q.LargeShirt=q.LargeShirt-qun;
					q.printInventory();
				}
				else
				{
				
					System.out.println("Order"+sno+" failed");
					q.printInventory();
				}
			}
		}
		else if(item=='C')	
		{
			synchronized(q)
			{
				if(q.Cap>=qun)
				{
					System.out.println("Order"+sno+" successfull");
					q.Cap=q.Cap-qun;
					q.printInventory();
				}
				else
				{
					System.out.println("Order"+sno+" failed");
					q.printInventory();
				}
			}
		}
	}
}
