import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Scanner;

public class Pep_JavaIP_10BinaryTrees_322ConstructFromPreOrder {
	private static class Node {
		int data;
		Node left;
		Node right;

		Node(int data, Node left, Node right) {
			this.data = data;
			this.left = left;
			this.right = right;
		}
	}

	public static void display(Node node) {
		if (node == null) {
			return;
		}

		String str = "";

		str += node.left == null ? "." : node.left.data;
		str += " => " + node.data + " <= ";
		str += node.right == null ? "." : node.right.data;

		System.out.println(str);

		display(node.left);
		display(node.right);
	}

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int[] preData = new int[Integer.parseInt(scn.next())];
		for (int i = 0; i < preData.length; i++) {
			preData[i] = Integer.parseInt(scn.next());
		}
		String[] lnData = new String[preData.length];
		for (int i = 0; i < lnData.length; i++) {
			lnData[i] = scn.next();
		}

		Node root = co(preData, lnData);
		if (root == null) {
			System.out.println("Invalid");
		} else {
			display(root);
		}
	}

	static int indx = 0;

	private static Node co(int[] preData, String[] lnData) {
        if(indx == preData.length) return null;
        
        Node a = new Node(preData[indx],null,null);
        int c=0;
        indx++;
        
        if(lnData[indx]=="L"){
            return a;
        }
                
        while(c<2){
            Node l = co(preData,lnData);
            if(c==0) a.left=l;
            else a.right=l;
            c++;
        }
        return a;
    }

}
