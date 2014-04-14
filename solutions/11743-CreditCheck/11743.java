import java.io.*;
import java.util.*;

class Main
{
    public static void main (String args[]) throws java.io.IOException
    {
        final BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        
        int t = Integer.parseInt(reader.readLine());
        
        // DEBUG System.out.println("T = [" + t + "]");
        
        for(int i = 0; i < t; ++i)
        {
            StringBuffer buffer = new StringBuffer(reader.readLine());
            
            for(int j = 0; j < buffer.length(); ++j)
            {
                // DEBUG System.out.println("CHECK c = [" + buffer.charAt(i) + "] i = " + j);
                if(buffer.charAt(j) == ' ')
                {
                    // DEBUG System.out.println("DELETE c = [" + buffer.charAt(i) + "] i = " + j);
                    buffer = buffer.deleteCharAt(j);
                }
            }    
                
            // DEBUG System.out.println("BUFFER = [" + buffer + "]");
            
            int odd_sum = 0;
            int even_sum = 0;

            for(int j = 0; j < buffer.length(); ++j)
            {
                // DEBUG System.out.println("buffer[" + j + "] = [" + buffer.charAt(j) + "]");
                if(j % 2 == 0) 
                {
                    int odd = 2 * (buffer.charAt(j) - '0');
                    if(odd > 9)
                    {
                        odd_sum += 1;
                        odd -= 10;
                    }
                    odd_sum += odd;
                    // DEBUG System.out.println("odd_sum = " + odd_sum + " odd = " + odd);
                }
                else
                {
                    int even = buffer.charAt(j) - '0';
                    even_sum += even;
                    // DEBUG System.out.println("even_sum = " + even_sum);
                }
            }

            int total = odd_sum + even_sum;
            // DEBUG System.out.println("TOTAL = " + total + " even_sum = " + even_sum + " odd_sum = " + odd_sum);
            if(total % 10 == 0)
                System.out.println("Valid");
            else
                System.out.println("Invalid");
        }
    }
}
