void
Forward( float th1, float th2, float th3,  float l1, float l2,
	 glm::mat4& m1g, glm::mat4& m2g, glm::mat4& m3g )
{

	// Need to be in radians
	th1 = th1 * (M_PI / 180.f);
	th2 = th2 * (M_PI / 180.f);
	th3 = th3 * (M_PI / 180.f);
	
	// Do the translations
	glm::mat4 translation1 = glm::translate(glm::mat4(1.f), glm::vec3(l1, 0, 0));
	glm::mat4 translation2 = glm::translate(glm::mat4(1.f), glm::vec3(l2, 0, 0));
	
	// Do the Rotations
	glm::mat4 rotation1 = glm::rotate(glm::mat4(1.f), th1, glm::vec3(0, 0, 1));
	glm::mat4 rotation2 = glm::rotate(glm::mat4(1.f), th2, glm::vec3(0, 0, 1));
	glm::mat4 rotation3 = glm::rotate(glm::mat4(1.f), th3, glm::vec3(0, 0, 1));
	
	// Put them together
	glm::mat4 cross2and1 = translation1 * rotation2; // [T_2/1] * [R_th2]
	glm::mat4 cross3and2 = translation2 * rotation3; // [T_3/2] * [R_th3]
	
	// Transform the matrices
	m1g = rotation1; // [M_1/g] = [T_1/g] * [R_th1]
	m2g = m1g * cross2and1; // [M_2/g] = [M_1/g] * [[T_2/1]*[R_th2]]
	m3g = m2g * cross3and2; // [M_3/g] = [M_1/g] * [[T_2/1]*[R_th2]] * [[T_3/2]*[R_th3]]

}

void
WhoAmI( std::string &yourName, std::string &yourEmailAddress )
{
        yourName = "Conner Rhea";
        yourEmailAddress = "rheac@oregonstate.edu" ;
}