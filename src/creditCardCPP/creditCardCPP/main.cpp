/*
 * creditCardCPP V1.0
 * Frank Bernal
 * CIS054 C/C++ Programming
 * Inputs: None
 * Outputs: balance, interest, payment, newBalance
 * 24 Feb 2022
 */

// Input Output stream
#include <iostream>
// Input Output Manipulation
#include <iomanip>
// std database
using namespace std;

// Constants for credit info
// Annual interest rate divided by 100 for proper deciaml
const double YEARLY_INTEREST_RATE = 22.4 / 100;
// Annual rate divided by 12 for monthly rate
const double MONTHLY_INTEREST_RATE = YEARLY_INTEREST_RATE / 12;
// Credit Limit
const double CREDIT_LIMIT = 500.00;
// 12 months defined for project output
const int MAX_MONTHS = 12;

// Start main
int main(int argc, const char * argv[]) {
    
    // Input values
    double balance = 231.96;
    double payment = 35.00;
    double charges = 0.00;
    
    // Computed values
    double interest;
    double balanceBeforePayment;
    double newBalance;
    int month = 1;   // Start at month 1 for counter
    
    // Table column headings
    cout << fixed << showpoint;
    cout << setw(7) << "Month" << setw(9) << "Balance" << setw(10) << "Interest" << setw(9) << "Payment"
    << setw(9) << "Charges" << setw(12) << "New Balance" << endl;
    
    // Start loop for output table
    do {
        interest = balance * MONTHLY_INTEREST_RATE;
        balanceBeforePayment = balance + interest + charges;
        // If balance is less than payment, set payment to balance
        if (balanceBeforePayment <= payment){
            payment = balanceBeforePayment;
        }   // End of change in payment
        // Continue computing
        newBalance = balanceBeforePayment - payment;
        
        // Display output table
        cout << setprecision(2);   // Display 2 digits past decimal
        cout << setw(7) << month << setw(9) << balance << setw(10) << interest << setw(9) << payment
        << setw(9) << charges << setw(12) << newBalance << endl;
        // Update month counter
        month++;
        // Update balance
        balance = newBalance;
    } while (balance > 0.00 && balance <= CREDIT_LIMIT && month <= MAX_MONTHS);
    // Exit loop when balance is 0.00, 500.00, or month reaches 12
    
    return 0;
}
