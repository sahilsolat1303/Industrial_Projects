import java.io.*;
import java.util.*;

class Unpaker 
{
    public static void main(String[] args) throws Exception
    {

        ////////// Variable Creation //////////
        String PackFileName = null;
        String Header = null;
        String Token[] = null;

        FileInputStream fiobj = null;
        File fobj = null;
        File fuobj = null;
        FileOutputStream foobj = null;

        int FileSize = 0;
        int iRet = 0;
        int i = 0;
        
        byte Buffer[] = null;
        byte bHeader[] = new byte[100];
        byte key = 0x11;

        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter the Pack File name :");
        PackFileName = sobj.nextLine();

        fobj = new File(PackFileName);

        if(fobj.exists())
        {
            fiobj = new FileInputStream(fobj);
            while ((iRet = fiobj.read(bHeader,0,100)) != -1) 
            {
                Header = new String(bHeader);

                Header = Header.trim();

                Token = Header.split(" ");

                System.out.println("File Name :"+Token[0]);
                System.out.println("File Size :"+Token[1]);


                fuobj = new File(Token[0]);

                fuobj.createNewFile();

                FileSize = Integer.parseInt(Token[1]);

                foobj = new FileOutputStream(fuobj);

                Buffer = new byte[FileSize];

                fiobj.read(Buffer, 0, FileSize);

                for(i = 0; i<FileSize; i++)
                {
                    Buffer[i] = (byte)(Buffer[i] ^ key);
                }

                foobj.write(Buffer, 0, FileSize);
                foobj.close();
            }
            fiobj.close();
            System.out.println("Unpacking Completed Successfully");
        }
        else
        {
            System.out.println("There is no such file");
        }
        sobj.close();
    }
}
