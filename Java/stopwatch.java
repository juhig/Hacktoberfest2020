# create a countdown stopwatch that counts by the second
# for more details see https://docs.oracle.com/javase/8/docs/api/javax/swing/Timer.html
 
import java.util.Timer;
import java.util.TimerTask;
 
public class Stopwatch {
  static int interval;
  static Timer timer;
 
  public static void main(String[] args) {
 
    int delay = 1000;
    int period = 1000;
    timer = new Timer();
    interval =10000;
    timer.scheduleAtFixedRate(new TimerTask() {
      public void run() {
         System.out.println(setInterval());
      }
    }, delay, period);
  }
 
  private static final int setInterval(){
    if( interval== 1) timer.cancel();
      return --interval;
  }
}
