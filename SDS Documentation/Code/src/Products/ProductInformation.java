/**
 * This class represents the information of a product, including its name, ID, description, price, discount amount,
 * category, brand, unit type, status, and quantity.
 */

package Products;
public class ProductInformation {
    String name;
    int id;
    String description;
    double price;
    double discountAmount;
    String category;
    String brand;
    UnitType unitType;
    Status status;
    int quantity;

    /**
     * Constructor for the ProductInformation class.
     * @param Name The name of the product.
     * @param description The description of the product.
     * @param price The price of the product.
     * @param discountAmount The discount amount of the product.
     * @param category The category of the product.
     * @param brand The brand of the product.
     * @param unitType The unit type of the product.
     * @param status The status of the product.
     * @param quantity The quantity of the product.
     * @param id The ID of the product.
     */
    public ProductInformation(String Name, String description, double price, double discountAmount,
                              String category, String brand, UnitType unitType, Status status, int quantity, int id) {
        this.id = id;
        this.name = Name;
        this.description = description;
        this.price = price;
        this.discountAmount = discountAmount;
        this.category = category;
        this.brand = brand;
        this.unitType = unitType;
        this.status = status;
        this.quantity = quantity;
    }

    /**
     * Returns the name of the product.
     * @return The name of the product.
     */
    public String getName() {
        return name;
    }

    /**
     * Returns the price of the product.
     * @return The price of the product.
     */
    public double getPrice() {
        return price;
    }

    /**
     * Returns the discount amount of the product.
     * @return The discount amount of the product.
     */
    public double getDiscountAmount() {
        return discountAmount;
    }

    /**
     * Returns the unit type of the product.
     * @return The unit type of the product.
     */
    public UnitType getUnitType() {
        return unitType;
    }

    /**
     * Returns the status of the product.
     * @return The status of the product.
     */
    public Status getStatus() {
        return status;
    }

    /**
     * Returns the quantity of the product.
     * @return The quantity of the product.
     */
    public int getQuantity() {
        return quantity;
    }

    /**
     * Returns the ID of the product.
     * @return The ID of the product.
     */
    public int getId() {
        return id;
    }

    /**
     * Prints the information of the product.
     */
    public void print() {
        System.out.print("\n--------------Product Information--------------");
        System.out.println(
                "\nName -> " + name +
                        "\nDescription -> " + description +
                        "\nPrice -> " + price +
                        "\nDiscount Amount -> " + discountAmount +
                        "\nCategory -> " + category +
                        "\nBrand -> " + brand +
                        "\nUnit Type -> " + unitType +
                        "\nStatus -> " + status +
                        "\nQuantity -> " + quantity
        );
    }

    /**
     * Sets the quantity of the product.
     * @param quantity The new quantity of the product.
     */
    public void setQuantity(int quantity) {
        this.quantity = quantity ;
    }
}

