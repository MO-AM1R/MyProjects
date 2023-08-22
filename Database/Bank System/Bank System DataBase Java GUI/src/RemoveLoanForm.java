import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.SQLException;

public class RemoveLoanForm extends JDialog{
    private JPanel panel1;
    private JButton removeLoanButton;
    private JTextField textFieldLoanNumber;
    private JTextField textFieldBankCode;
    private JTextField textFieldBranchNumber;
    private JButton cancelButton;

    public RemoveLoanForm(JFrame parent,int ssn)  // Constructor.
    {
        // Setting the attributes of the panel.
        super(parent);
        setTitle("Loans List");
        setContentPane(panel1);
        setMinimumSize(new Dimension(1300, 700));
        setLocationRelativeTo(parent);
        setDefaultCloseOperation(DISPOSE_ON_CLOSE);
        setVisible(true);
        setModal(true);

        removeLoanButton.addActionListener(e -> { // Button to remove Loan
            try {
                DataBase dataBase = new DataBase();

                if (!LoginForm.checkNumber(textFieldBankCode.getText()) ||
                        !LoginForm.checkNumber(textFieldBranchNumber.getText()) ||
                        !LoginForm.checkNumber(textFieldLoanNumber.getText())){

                    return ;
                }

                if(dataBase.removeLoan(Integer.parseInt(textFieldBankCode.getText()),
                                Integer.parseInt(textFieldBranchNumber.getText()),
                                Integer.parseInt(textFieldLoanNumber.getText()))){

                    JOptionPane.showMessageDialog(null,
                            "Loan deleted successfully!",
                            "Successful Operation!",
                            JOptionPane.INFORMATION_MESSAGE);

                    new EmployeeForm(null, ssn) ;
                    dispose() ;
                }
                else{
                    JOptionPane.showMessageDialog(null,
                            "The loan is not exist",
                            "Invalid Information",
                            JOptionPane.ERROR_MESSAGE);
                }
            }
            catch (SQLException ex) {
                throw new RuntimeException(ex);
            }
        });
        cancelButton.addActionListener(e -> {
            new EmployeeForm(null, ssn) ;
            dispose() ;
        });
    }
}
