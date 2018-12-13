import org.junit.Test;

import static org.junit.Assert.*;

public class MainTest {
    @Test
    public void testFizzBuzzReturnsFizzWhenMultipleOf3(){
        assertEquals("Fizz", Main.fizzBuzz(3));
        assertEquals("Fizz", Main.fizzBuzz(33));
    }

    @Test
    public void testFizzBuzzReturnsBuzzWhenMultipleOf5(){
        assertEquals("Buzz",Main.fizzBuzz(5));
        assertEquals("Buzz",Main.fizzBuzz(20));
    }

    @Test
    public void testFizzBuzzReturnsFizzBuzzWhenMultipleOf3And5(){
        assertEquals("FizzBuzz", Main.fizzBuzz(15));
        assertEquals("FizzBuzz", Main.fizzBuzz(30));
    }

    @Test
    public void testFizzBuzzReturnsInputWhenNotMultipleOf3And5(){
        assertEquals("7",Main.fizzBuzz(7));
        assertEquals("19",Main.fizzBuzz(19));
    }
}