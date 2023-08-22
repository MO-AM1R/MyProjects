/**

 CustomerInformation class represents the information of a customer, including their name, ID, address, password, email, and status.
 It also provides a print method to display the information.
 @author Mohamed Amir
 @version 3.1
 */

package User;

public class CustomerInformation {
    private final String Name ;
    private final int id ;
    private final Address address ;
    private final String Password;
    private final String Email;
    private final CustomerStatus status ;

    /**
     * Constructor for CustomerInformation class
     * @param name The name of the customer
     * @param id The ID of the customer
     * @param address The address of the customer
     * @param password The password of the customer
     * @param email The email of the customer
     * @param status The status of the customer
     */
    public CustomerInformation(String name, int id, Address address, String password, String email, CustomerStatus status) {
        Name = name;
        this.id = id;
        this.address = address;
        Password = password;
        Email = email;
        this.status = status;
    }

    /**
     * Getter method for Name
     * @return The name of the customer
     */
    public String getName() {
        return Name;
    }

    /**
     * Getter method for ID
     * @return The ID of the customer
     */
    public int getId() {
        return id;
    }

    /**
     * Getter method for Address
     * @return The address of the customer
     */
    public Address getAddress() {
        return address;
    }

    /**
     * Getter method for Password
     * @return The password of the customer
     */
    public String getPassword() {
        return Password;
    }

    /**
     * Getter method for Email
     * @return The email of the customer
     */
    public String getEmail() {
        return Email;
    }

    /**
     * Getter method for Status
     * @return The status of the customer
     */
    public CustomerStatus getStatus() {
        return status;
    }

    /**
     * Method to display the information of the customer
     */
    public void print() {
        System.out.print("<--------------User Information-------------->\n");
        System.out.println("Name -> " + Name + "\nId -> " + id +
                "\nEmail -> " + Email + "\nStatus -> " + status);

        address.print() ;
    }

}
