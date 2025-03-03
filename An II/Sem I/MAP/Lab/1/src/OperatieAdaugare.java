public class OperatieAdaugare extends ComplexExpresion{
    public OperatieAdaugare(NumarComplex[] args) {
        super(Operation.ADDITION, args);
    }

    @Override
    public NumarComplex executeOneOperation(NumarComplex operand1, NumarComplex operand2) {
        operand1.adunare(operand2);
        return operand1;
    }
}
