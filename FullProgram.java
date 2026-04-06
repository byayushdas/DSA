// FullProgram.java
import java.util.Scanner;
import java.io.FileWriter;
import java.io.IOException;

// Custom Exception
class InsufficientFundsException extends Exception {
    public InsufficientFundsException(String message) {
        super(message);
    }
}

// BankAccount Class
class BankAccount {
    private String accountNumber;
    private String accountHolderName;
    private double balance;

    public BankAccount(String accountNumber, String accountHolderName, double balance) {
        this.accountNumber = accountNumber;
        this.accountHolderName = accountHolderName;
        this.balance = balance;
    }

    // Deposit
    public void deposit(double amount) {
        try {
            if (amount < 0) {
                throw new IllegalArgumentException("Deposit amount cannot be negative.");
            }
            balance += amount;
            System.out.println("Deposited: " + amount);
            logTransaction("Deposited: " + amount);
        } catch (IllegalArgumentException e) {
            System.out.println("Error: " + e.getMessage());
            logTransaction("Failed Deposit: " + e.getMessage());
        }
    }

    // Withdraw
    public void withdraw(double amount) throws InsufficientFundsException {
        if (amount > balance) {
            throw new InsufficientFundsException("Insufficient balance.");
        }
        balance -= amount;
        System.out.println("Withdrawn: " + amount);
        logTransaction("Withdrawn: " + amount);
    }

    // Transfer
    public void transfer(double amount, BankAccount recipient) {
        try {
            this.withdraw(amount);
            recipient.deposit(amount);
            System.out.println("Transfer successful.");
            logTransaction("Transferred " + amount + " to " + recipient.accountHolderName);
        } catch (InsufficientFundsException e) {
            System.out.println("Transfer Failed: " + e.getMessage());
            logTransaction("Failed Transfer: " + e.getMessage());
        }
    }

    // Display
    public void displayDetails() {
        System.out.println("\nAccount Number: " + accountNumber);
        System.out.println("Account Holder: " + accountHolderName);
        System.out.println("Balance: " + balance);
    }

    // Logging to file
    private void logTransaction(String message) {
        try {
            FileWriter fw = new FileWriter("transactions.txt", true);
            fw.write(message + "\n");
            fw.close();
        } catch (IOException e) {
            System.out.println("Logging failed.");
        }
    }
}

// Main Class
public class FullProgram {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        // ===== PART 1: Built-in Exceptions =====

        // ArithmeticException
        try {
            int x = 10 / 0;
        } catch (ArithmeticException e) {
            System.out.println("ArithmeticException: Cannot divide by zero.");
        }

        // ArrayIndexOutOfBoundsException
        int[] array = new int[5];
        try {
            System.out.println(array[10]);
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("ArrayIndexOutOfBoundsException: Invalid index accessed.");
        }

        // ClassCastException
        Object obj = "Hello";
        try {
            int num = (int) obj;
        } catch (ClassCastException e) {
            System.out.println("ClassCastException: Cannot cast object to incompatible type.");
        }

        // IllegalArgumentException
        try {
            methodWithInvalidArgument(-1);
        } catch (IllegalArgumentException e) {
            System.out.println("IllegalArgumentException: " + e.getMessage());
        }

        // ===== PART 2: Bank System =====

        BankAccount acc1 = new BankAccount("101", "Ayush", 5000);
        BankAccount acc2 = new BankAccount("102", "Rahul", 3000);

        acc1.displayDetails();
        acc2.displayDetails();

        // Deposit
        acc1.deposit(1000);
        acc1.deposit(-500); // Invalid

        // Withdraw with retry
        boolean success = false;
        while (!success) {
            try {
                System.out.print("\nEnter amount to withdraw: ");
                double amt = sc.nextDouble();

                acc1.withdraw(amt);
                success = true;

            } catch (InsufficientFundsException e) {
                System.out.println("Error: " + e.getMessage());
                System.out.println("Try again...\n");
            }
        }

        // Transfer
        acc1.transfer(2000, acc2);

        // Final Details
        acc1.displayDetails();
        acc2.displayDetails();

        sc.close();
    }

    // Method for IllegalArgumentException
    public static void methodWithInvalidArgument(int arg) {
        if (arg < 0) {
            throw new IllegalArgumentException("Argument cannot be negative.");
        }
    }
}