/**

 The Address class represents a physical address with its various components.
 An address is composed of a governorate, district, street, building number, building floor, building flat, and landmark.
 This class provides methods for getting each component of the address and printing out the full address.
 This class is used in various parts of the system to represent the address of a user or a business.
 @author Mohamed Amir
 @version 3.1
 */

package User;
public class Address {
    String governorate ;
    String district ;
    String street ;
    int buildingNumber ;
    int buildingFloor ;
    int buildingFlat ;
    String Landmark ;

    /**
     * Constructs a new Address object with the specified components.
     *
     * @param governorate the governorate of the address
     * @param district the district of the address
     * @param street the street of the address
     * @param buildingNumber the building number of the address
     * @param buildingFloor the building floor of the address
     * @param buildingFlat the building flat of the address
     * @param landmark the landmark of the address
     */

    public Address(String governorate, String district, String street, int buildingNumber, int buildingFloor, int buildingFlat, String landmark) {
        this.governorate = governorate;
        this.district = district;
        this.street = street;
        this.buildingNumber = buildingNumber;
        this.buildingFloor = buildingFloor;
        this.buildingFlat = buildingFlat;
        Landmark = landmark;
    }

    /**
     * Gets the governorate of the address.
     *
     * @return the governorate of the address
     */
    public String getGovernorate() {
        return governorate;
    }

    /**
     * Gets the district of the address.
     *
     * @return the district of the address
     */
    public String getDistrict() {
        return district;
    }

    /**
     * Gets the street of the address.
     *
     * @return the street of the address
     */
    public String getStreet() {
        return street;
    }

    /**
     * Gets the building number of the address.
     *
     * @return the building number of the address
     */
    public int getBuildingNumber() {
        return buildingNumber;
    }

    /**
     * Gets the building floor of the address.
     *
     * @return the building floor of the address
     */
    public int getBuildingFloor() {
        return buildingFloor;
    }

    /**
     * Gets the building flat of the address.
     *
     * @return the building flat of the address
     */
    public int getBuildingFlat() {
        return buildingFlat;
    }

    /**
     * Gets the landmark of the address.
     *
     * @return the landmark of the address
     */
    public String getLandmark() {
        return Landmark;
    }

    /**
     * Prints out the full address of the Address object.
     */
    public void print() {
        System.out.println("<--------------Address-------------->");
        System.out.println("governorate -> " + governorate + "\ndistrict -> " + district + "\nstreet -> " + street +
                "\nbuildingNumber -> " + buildingNumber + "\nbuildingFloor -> " + buildingFloor + "\nbuildingFlat -> " +
                buildingFlat + "\nLandmark -> " + Landmark);
    }

    /**
     * Returns a string representation of the Address object.
     *
     * @return a string representation of the Address object
     */
    public String toString() {
        return  governorate + " - " + district + " - " + street + " - " + buildingNumber + " - " + buildingFloor + " - " +
                buildingFlat + " - " + Landmark ;
    }
}
