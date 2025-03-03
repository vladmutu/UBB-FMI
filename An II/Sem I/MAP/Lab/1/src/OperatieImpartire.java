public class OperatieImpartire extends ComplexExpresion {
    public OperatieImpartire(NumarComplex[] args) {
        super(Operation.DIVISION, args);
    }

    @Override
    public NumarComplex executeOneOperation(NumarComplex operand1, NumarComplex operand2) {
        operand1.impartire(operand2);
        return operand1;
    }
}
