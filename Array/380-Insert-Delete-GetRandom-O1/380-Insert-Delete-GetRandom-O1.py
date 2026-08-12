class RandomizedSet(object):

    def __init__(self):
       self.ls=[]


    def insert(self, val):
        """
        :type val: int
        :rtype: bool
        """
        if val not in self.ls: 
           self.ls.append(val)
           return True
        else:
            return False
        

    def remove(self, val):
        """
        :type val: int
        :rtype: bool
        """
        if val in self.ls: 
           self.ls.remove(val)
           return True
        else:
            return False
        
        

    def getRandom(self):
        """
        :rtype: int
        """
        import random as r
        return random.choice(self.ls)

        


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()