public class Main {
    public static void main(String [] args){
        System.out.println("Hello world !");
    }

    public static String fizzBuzz(int n){
//          return (n%3==0 && n%5==0) ? "FizzBuzz" : ((n%3==0) ? "Fizz" : ((n%5==0) ? "Buzz":(""+n)));
        boolean divBy3 = n % 3 == 0;
        boolean divBy5 = n % 5 == 0;
        if(divBy3 && divBy5){
           return "FizzBuzz";
        }else if(divBy3){
            return "Fizz";
        }else if(divBy5){
            return "Buzz";
        }else{
            return "" + n;
        }
    }
}
