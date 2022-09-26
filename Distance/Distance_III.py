from math import sqrt #only need sqrt so not importing entire module

class Point():
    """A class that takes 3 inputs and assigns those to x, y, and z.
       Can return or change any coordinate and calculate distance given another instance of Point"""
    def __init__(self, _x=0.0, _y=0.0, _z=0.0):
        self.a = _x
        self.b = _y
        self.c = _z

        #getters; Return requested value

    def get_x(self):
        return float(self.a)

    def get_y(self):
        return float(self.b)

    def get_z(self):
        return float(self.c)

        #setters; Return Nothing
    
    def set_x(self, inp):
        self.a = inp
        return None

    def set_y(self, inp):
        self.b = inp
        return None

    def set_z(self, inp):
        self.c = inp
        return None
    
    def distance(self, other):
        """Takes an input of a Point object, rejecting the input if it is not an instance of Point.
           Gets distance between current and input instances of Point and returns output as an Int"""
        if isinstance(other, Point) == False:
            return 'Not a Valid Point'
        dist_x = (self.get_x() - other.get_x()) ** 2
        dist_y = (self.get_y() - other.get_y()) ** 2
        dist_z = (self.get_z() - other.get_z()) ** 2
        total_dist = sqrt(dist_x + dist_y + dist_z)
        return total_dist

def main():
    with open('points.txt', 'r') as points: #opens points.txt and reads each line into a list as strings
        point_list = points.readlines()

    with open('result.txt', 'w') as result: #holds results.txt open to be written into
        for coordset in point_list: #iterates through the point list made above, breaking each str into 2 Point classes
            if len(coordset) == 1:
                continue
            set = coordset.split()
            point1 = Point(set[0], set[1], set[2]) #assigns first half of str to first point and second half to second
            point2 = Point(set[3], set[4], set[5])
            result.write(f'{point1.distance(point2):.2f}\n') #writes the calculated distance between the points to results.txt
main()