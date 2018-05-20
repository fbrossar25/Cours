public class Instruction{	
	private int curState;
	private int nextState;
	private boolean symbol;
	private String actions;
	
	Instruction(int curState, boolean symbol, String actions, int nextState){
		this.curState = curState;
		this.symbol = symbol;
		this.actions = actions;
		this.nextState = nextState;
	}
	
	Instruction(Instruction i){
		this.curState = i.curState;
		this.symbol = i.symbol;
		this.actions = i.actions;
		this.nextState = i.nextState;
	}
	
	Instruction(){
		this(0,false,"n",0);
	}
	
	int getCurState(){
		return this.curState;
	}
	
	int getNextState(){
		return this.nextState;
	}
	
	boolean getSymbol(){
		return this.symbol;
	}
	
	String getActions(){
		return this.actions;
	}
	
	public String toString(){
		String s = "<";
		s += this.curState+", '";
		s += this.symbol ? "1', " : "0', ";
		s += this.actions+", ";
		s += this.nextState+">";
		return s;
	}
}
