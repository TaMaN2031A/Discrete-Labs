
import java.util.ArrayList;
import java.util.Scanner;

class powerSet {
    private int setSize;
    private ArrayList<String> set = new ArrayList<String>();
    private ArrayList<String> rec_set = new ArrayList<String>();
    private int choice;
    private int powerSetSize;
    Scanner in = new Scanner(System.in);
    private void iterative()
    {
        int counter, j;
        for(counter = 0; counter < powerSetSize; counter++)
        {
            int o = 0;
            System.out.print("{");
            for(j = 0; j < setSize; j++)
            {
                if((counter & (1 << j)) > 0) {
                    if(o++!=0)
                        System.out.print(", ");
                    System.out.print(set.get(j));
                }
            }
            System.out.println("}");
        }
    }

    private void recursiveSolver(ArrayList<String> a,ArrayList<String> b,String sum,int j)
    {
        if(j>=set.size()){
            rec_set.add(sum);
            return;
        }
        recursiveSolver(a,b,sum.length()>0?sum+", "+a.get(j):sum+a.get(j),j+1);
        recursiveSolver(a,b,sum,j+1);





    }
    private void recursive()
    {
        String s=new String();
        rec_set.clear();
        recursiveSolver(set,rec_set,s,0);
        for(int j = 0; j < rec_set.size(); j++)
        {
            System.out.print("{");
            System.out.print(rec_set.get(j));
            System.out.println("}");

        }


    }
    public void welcomeSender()
    {
        System.out.println("Welcome Sir.");
        System.out.println("Hope You enjoy the application.");
        System.out.println("We'll Ask you to insert some details about the " +
                "Set, to please type ok");
    }
    public void inputTaker()
    {
        set.clear();
        System.out.println("Thank You for preceding to this level.");
        System.out.println("Please enter number the size of the set.");
        setSize = in.nextInt();
        powerSetSize = (1<<setSize);
        System.out.println("Please insert the elements now.");
        System.out.println("To proceed type ok.");
        while(true)
        {
            String enter = in.nextLine();
            if(enter.equals("ok"))
                break;
        }
        for(int i = 1; i <= setSize; i++)
        {
            String buffer;
            if(i == 1)
                System.out.println("Insert 1st element");
            else if(i == 2)
                System.out.println("Insert 2nd element");
            else if(i == 3)
                System.out.println("Insert 3rd element");
            else
                System.out.println("Insert "+i+"th " + "element");
            buffer=in.nextLine();
            set.add(buffer);
        }
        System.out.println("Thank you, now input is taken successfully.");
        System.out.println("To Proceed please type ok");
        while(true)
        {
            String enter = in.nextLine();
            if(enter.equals("ok"))
                break;
        }
    }
    public void implementer()
    {
        System.out.println("Now, we will implement the power set operation.");
        System.out.println("Please choose the way you want to implement the operation");
        System.out.println("For iterative method press 1, for recursive press 2");
        choice = in.nextInt();
        if(choice==1)
            iterative();
        else
            recursive();

        end();
    }
    public void end(){
        System.out.println("\n--------------------------------------------------------------------------------");
        System.out.println("if you want to end press 0");
        System.out.println("To Take new input press 1 For iterative in old input method press 2, for recursive in old input press 3");
        choice = in.nextInt();
        if(choice==0){
            System.out.println("thank you.");
            System.exit(0);

        }
        if(choice==1){
            inputTaker();
            implementer();
        }
        if(choice==2) {

            iterative();
        }
        else
            recursive();

        end();

    }
}


public class Main {

    public static void main(String[] args) {
        powerSet strong = new powerSet();
        strong.welcomeSender();
        Scanner in = new Scanner(System.in);
        while(true)
        {
            String enter = in.nextLine();
            if(enter.equals("ok"))
            {
                strong.inputTaker();
                break;
            }
        }
        strong.implementer();
    }
}
