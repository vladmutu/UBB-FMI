public class OperatieInmultire extends ComplexExpresion {
    public OperatieInmultire(NumarComplex[] args) {
        super(Operation.MULTIPLICATION, args);
    }

    @Override
    public NumarComplex executeOneOperation(NumarComplex operand1, NumarComplex operand2) {
        operand1.inmultire(operand2);
        return operand1;
    }
}
