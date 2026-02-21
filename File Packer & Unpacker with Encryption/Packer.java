import java.io.*;
import java.util.*;

class Packer
{
    public static void main(String[] args)throws Exception
    {
       ////////// Variable Creation //////////

       String FolderName = null;
       String PackFileName = null;
       String Header = null;

       FileInputStream fiobj = null;
       FileOutputStream foobj = null;
       File fobj = null;
       File fpobj = null;

       int iRet = 0;
       int i = 0;
       int j = 0;
       int k = 0;


       byte Buffer[] = new byte[1024];
       byte bHeader[] = new byte[100];

       byte key = 0x11;

       Scanner sobj = new Scanner(System.in);
       
       System.out.println("Enter Folder Name :");
       FolderName = sobj.nextLine();

       fobj = new File(FolderName);

       if((fobj.exists()) && (fobj.isDirectory()))
       {
            System.out.println("Enter Pack File Name:");
            PackFileName = sobj.nextLine();

            fpobj = new File(PackFileName);
            if(fpobj.exists())
            {
               System.out.println("File Already Present");
               return; 
            }
            else
            {
                fpobj.createNewFile();
            }            

            File fArr[] = fobj.listFiles();
            if(fArr == null)
            {
                System.out.println("Folder is empty");
                return;
            }

            foobj = new FileOutputStream(fpobj);

            for(i = 0; i<fArr.length;i++)
            {
                
                if(fArr[i].getName().endsWith(".txt"))
                {
                    fiobj = new FileInputStream(fArr[i]);

                    Header = fArr[i].getName()+" "+fArr[i].length();
                    for(k = Header.length(); k<100;k++)
                    {
                        Header = Header + " ";
                    }
                    bHeader = Header.getBytes();

                    foobj.write(bHeader,0,100);

                    while ((iRet = fiobj.read(Buffer)) != -1) 
                    {
                        for(j =0; j<iRet;j++)
                        {
                            Buffer[j] = (byte)(Buffer[j] ^ key);
                        }
                        foobj.write(Buffer,0,iRet);    
                    }
                    fiobj.close();
                }                
            }
            foobj.close();
            sobj.close();
            System.out.println("Packing Completed Successfully");
       }
       else
       {
            System.out.println("There is no such File");
       }
       
    }
    
}
