import java.io.*;
import java.util.*;
import java.math.*;

class Main
{
    public static void main (String args[]) throws java.io.IOException
    {
        final BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        int t = 0;

        while(true)
        {
            StringTokenizer tokenizer = new StringTokenizer(reader.readLine());

            int r = Integer.parseInt(tokenizer.nextToken());
            int n = Integer.parseInt(tokenizer.nextToken());

            //int r = scanner.nextInt();
            //int n = scanner.nextInt();

            // DEBUG System.out.println("r = " + r + " n = " + n);

            if(r == 0 && n == 0) break;

            r -= n;

            // DEBUG System.out.println("r = " + r);

            if(r < 0) r = 0;

            double d = Math.ceil((double) r / (double) n);
            
            // DEBUG System.out.println("d = " + d);
            
            if(d <= 26)
                System.out.println("Case " + (++t) + ": " + (int) d);
            else
                System.out.println("Case " + (++t) + ": impossible");

        }
    }
}

