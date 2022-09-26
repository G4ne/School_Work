class Vector():
    def __init__(self, _x, _y, _z):
        self._a = _x
        self._b = _y
        self._c = _z

        #getters; Return requested value

    def get_x(self):
        return float(self._a)

    def get_y(self):
        return float(self._b)

    def get_z(self):
        return float(self._c)

        #setters; Return Nothing
    
    def set_x(self, inp):
        self._a = inp
        return None

    def set_y(self, inp):
        self._b = inp
        return None

    def set_z(self, inp):
        self._c = inp
        return None
    
    def __mul__(self, other):
        """Takes a Vector instance as input
           Multiplies own first, second, and third point with their corresponding point in the input instance
           then adds them to get dot product"""
        a_product = self.get_x() * other.get_x()
        b_product = self.get_y() * other.get_y()
        c_product = self.get_z() * other.get_z()
        product = a_product + b_product + c_product
        return product

with open('vectors.txt', 'r') as vectors: #opens and reads all lines in vectors.txt into vector_points
    vector_points = vectors.readlines()

def main():
    with open('result.txt', 'w') as result: #holds result.txt open for writing
        for vectorlist in vector_points: 
            if len(vectorlist) == 1: #checks if item in vector_points is empty
                continue
            set = vectorlist.split()
            vector1 = Vector(set[0], set[1], set[2]) #creates an instance of Vector for each Vector
            vector2 = Vector(set[3], set[4], set[5])
            dot_prod = vector1 * vector2
            result.write(f'{dot_prod:.2f}\n') #writes the dot product to result.txt with 2 decimal places
main()