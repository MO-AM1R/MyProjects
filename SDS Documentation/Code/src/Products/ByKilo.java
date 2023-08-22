/**
 * The `ByKilo` class implements the `UnitType` interface and represents a product sold by weight in kilograms.
 * It defines a maximum amount that can be purchased for this type of product.
 */

package Products;
public class ByKilo implements  UnitType {
        /**
         * Returns the maximum amount that can be purchased for this type of product.
         *
         * @return the maximum amount that can be purchased for this type of product (in kilograms)
         */
        public int getMaxAmount(){
                return 10;
};
}
