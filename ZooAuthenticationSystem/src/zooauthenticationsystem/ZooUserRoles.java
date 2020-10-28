package zooauthenticationsystem;
//Author Joshua McNew

class ZooUserRoles {
    private String role; //Creates private Strings role and user
    private String user;

    public void setUser(String userInput) {
        user = userInput;
    }

    public String getRole() {  //Switch statement that holds all of the given credentials
        switch (user) {
            case "Joshua.McNew":
                role = "author";
                System.out.println("You are the author of this program, congratulations!\n");
                break;
            case "Bethony.M":
                role = "wife";
                System.out.println("Hey I hope my wife doesn't see this.\n");
                break;
            case "griffin.keyes":
            case "donald.monkey":
                role = "zookeeper";
                System.out.println("Hello, Zookeeper!");
                System.out.print("As zookeeper, you have access to all of the animals' information and their daily monitoring logs.\n");
                System.out.println("This allows you to track their feeding habits, habitat conditions, and general welfare.\n");
                break;
            case "rosario.dawson":
            case "bruce.grizzlybear":
                role = "admin";
                System.out.println("Hello, System Admin!");
                System.out.print("As administrator, you have access to the zoo's main computer system.\n");
                System.out.println("This allows you to monitor users in the system and their roles.\n");
                break;
            case "bernie.gorilla":
            case "jerome.grizzlybear":
                role = "veterinarian";
                System.out.println("Hello, Veterinarian");
                System.out.print("As veterinarian, you have access to all of the animals' health records.\n");
                System.out.println("This allows you to view each animal's medical history and current treatments/illnesses (if any), and to maintain a vaccination log.\n");
                break;
            default:
                break; 
        }
        return role; //Returns matched role
    }
}