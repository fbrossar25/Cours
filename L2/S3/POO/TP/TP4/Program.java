public class Program{
	private Instruction code [];
	private String name;
	private int line=0;
	
	Program(String name, int n){
		this.name = name;
		this.code = new Instruction [n];
	}
	
	Program(){
		this("noName", 100);
	}
	
	boolean add(Instruction toAdd){
		if(this.line < this.code.length){
			this.code[this.line] = toAdd;
			this.line++;
			return true;
		}
		else return false;
	}
	
	boolean add(int curState, boolean symbol, String actions, int nextState){
		return add(new Instruction(curState, symbol, actions, nextState));
	}
	
	Instruction getInstruction(int state, boolean symbol){
		Instruction res = new Instruction();
		int i=0;
		boolean found = false;
		do{
			if(code[i].getSymbol() == symbol && code[i].getCurState() == state){
				found = true;
			}
			i++;
		}while(i<code.length && !found);
		if (!found) res = new Instruction();
		else res = new Instruction(code[i-1]);
		return res;
	}
	
	String getName(){
		return this.name;
	}
	
	public String toString(){
		String s = "Programme "+this.name+"\n";
		for(int i=0; i<this.code.length; i++){
			s += i+": "+this.code[i].toString()+"\n";
		}
		return s;
	}
}
