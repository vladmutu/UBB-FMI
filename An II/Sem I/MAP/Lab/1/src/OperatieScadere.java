public class OperatieScadere extends ComplexExpresion {
    public OperatieScadere(NumarComplex[] args) {
        super(Operation.SUBSTRACTION, args);
    }

    @Override
    public NumarComplex executeOneOperation(NumarComplex operand1, NumarComplex operand2) {
        operand1.scadere(operand2);
        return operand1;
    }
}
