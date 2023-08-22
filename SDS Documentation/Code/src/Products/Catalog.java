/**
 * A catalog class that contains a list of available products.
 */
package Products;
import Database.Control;
import java.util.List;

public class Catalog {
    private static List<Product> products;

    /**
     * Loads the available products from the database.
     */
    public static void LoadProducts(){
        products = Control.LoadProducts() ;
    }

    /**
     * Prints all the available products in the catalog.
     */
    public void print() {
        for (Product p : products) {
            p.getInfo().print() ;
        }
    }

    /**
     * Returns a product based on its name, category and brand.
     *
     * @param pName the name of the product to search for
     * @param pCategory the category of the product to search for
     * @param pBrand the brand of the product to search for
     * @return the product with the given name, category and brand, or null if not found
     */
    public Product getProduct(String pName, String pCategory, String pBrand) {
        for (Product product : products) {
            if (pBrand.equals(product.getInfo().brand) &&
                    pCategory.equals(product.getInfo().category) &&
                        pName.equals(product.getInfo().name)){
                return product ;
            }
        }
        return null ;
    }
}
