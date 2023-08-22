/**

 The CustomerStatus enumeration represents the possible statuses that a customer can have.
 A customer can either be suspended or unsuspended.
 This enumeration is used in the User class to determine the status of a customer account.
 @author Mohamed Amir
 @version 3.1
 */

package User;

public enum CustomerStatus {
    /**
     * The customer account is currently suspended and cannot be used.
     */
    Suspended,

    /**
     * The customer account is currently unsuspended and can be used normally.
     */
    unSuspended
}
