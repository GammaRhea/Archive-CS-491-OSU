glm::vec3
WhatPartOfALivesInBDir( glm::vec3 a, glm::vec3 b )
{
	return glm::dot(a, glm::normalize(b)) * glm::normalize(b);
}


glm::vec3
WhatPartOfALivesPerpToB( glm::vec3 a, glm::vec3 b )
{
	return a - WhatPartOfALivesInBDir(a, b);
}


glm::vec3
UnitSurfaceNormal( glm::vec3 q, glm::vec3 r, glm::vec3 s )
{
	return glm::normalize(glm::cross((r - q), (s - q)));
}


float
Area( glm::vec3 q, glm::vec3 r, glm::vec3 s )
{
	return (float)0.5 * glm::length(glm::cross((r - q), (s - q)));
}


bool
IsPointInTriangle( glm::vec3 q, glm::vec3 r, glm::vec3 s, glm::vec3 p )
{
	glm::vec3 n = glm::cross((r - q), (s - q));
	glm::vec3 nq = glm::cross((r - q), (p - q));
	glm::vec3 nr = glm::cross((s - r), (p - r));
	glm::vec3 ns = glm::cross((q - s), (p - s));

	return ((glm::dot(n, nq) > 0) && (glm::dot(n, nr) > 0) && (glm::dot(n, ns) > 0));
}



float
DistanceFromPointToPlane( glm::vec3 q, glm::vec3 r, glm::vec3 s, glm::vec3 p )
{
	return glm::dot((p - q), UnitSurfaceNormal(q, r, s));
}


void
WhoAmI( std::string &yourName, std::string &yourEmailAddress )
{
	yourName = "Conner Rhea";
	yourEmailAddress = "rheac@oregonstate.edu";
}