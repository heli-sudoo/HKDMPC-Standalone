"""LCM type definitions
This file automatically generated by lcm.
DO NOT MODIFY BY HAND!!!!
"""

try:
    import cStringIO.StringIO as BytesIO
except ImportError:
    from io import BytesIO
import struct

class hkd_problem_data_lcm_t(object):
    __slots__ = ["n_timesteps", "contacts", "times", "pos_r", "eul_r", "vel_r", "omega_r", "qdummy_r", "pos", "eul", "vel", "omega", "qdummy"]

    __typenames__ = ["int32_t", "float", "float", "float", "float", "float", "float", "float", "float", "float", "float", "float", "float"]

    __dimensions__ = [None, [4, "n_timesteps"], ["n_timesteps"], [3, "n_timesteps"], [3, "n_timesteps"], [3, "n_timesteps"], [3, "n_timesteps"], [12, "n_timesteps"], [3, "n_timesteps"], [3, "n_timesteps"], [3, "n_timesteps"], [3, "n_timesteps"], [12, "n_timesteps"]]

    def __init__(self):
        self.n_timesteps = 0
        self.contacts = [ [] for dim0 in range(4) ]
        self.times = []
        self.pos_r = [ [] for dim0 in range(3) ]
        self.eul_r = [ [] for dim0 in range(3) ]
        self.vel_r = [ [] for dim0 in range(3) ]
        self.omega_r = [ [] for dim0 in range(3) ]
        self.qdummy_r = [ [] for dim0 in range(12) ]
        self.pos = [ [] for dim0 in range(3) ]
        self.eul = [ [] for dim0 in range(3) ]
        self.vel = [ [] for dim0 in range(3) ]
        self.omega = [ [] for dim0 in range(3) ]
        self.qdummy = [ [] for dim0 in range(12) ]

    def encode(self):
        buf = BytesIO()
        buf.write(hkd_problem_data_lcm_t._get_packed_fingerprint())
        self._encode_one(buf)
        return buf.getvalue()

    def _encode_one(self, buf):
        buf.write(struct.pack(">i", self.n_timesteps))
        for i0 in range(4):
            buf.write(struct.pack('>%df' % self.n_timesteps, *self.contacts[i0][:self.n_timesteps]))
        buf.write(struct.pack('>%df' % self.n_timesteps, *self.times[:self.n_timesteps]))
        for i0 in range(3):
            buf.write(struct.pack('>%df' % self.n_timesteps, *self.pos_r[i0][:self.n_timesteps]))
        for i0 in range(3):
            buf.write(struct.pack('>%df' % self.n_timesteps, *self.eul_r[i0][:self.n_timesteps]))
        for i0 in range(3):
            buf.write(struct.pack('>%df' % self.n_timesteps, *self.vel_r[i0][:self.n_timesteps]))
        for i0 in range(3):
            buf.write(struct.pack('>%df' % self.n_timesteps, *self.omega_r[i0][:self.n_timesteps]))
        for i0 in range(12):
            buf.write(struct.pack('>%df' % self.n_timesteps, *self.qdummy_r[i0][:self.n_timesteps]))
        for i0 in range(3):
            buf.write(struct.pack('>%df' % self.n_timesteps, *self.pos[i0][:self.n_timesteps]))
        for i0 in range(3):
            buf.write(struct.pack('>%df' % self.n_timesteps, *self.eul[i0][:self.n_timesteps]))
        for i0 in range(3):
            buf.write(struct.pack('>%df' % self.n_timesteps, *self.vel[i0][:self.n_timesteps]))
        for i0 in range(3):
            buf.write(struct.pack('>%df' % self.n_timesteps, *self.omega[i0][:self.n_timesteps]))
        for i0 in range(12):
            buf.write(struct.pack('>%df' % self.n_timesteps, *self.qdummy[i0][:self.n_timesteps]))

    def decode(data):
        if hasattr(data, 'read'):
            buf = data
        else:
            buf = BytesIO(data)
        if buf.read(8) != hkd_problem_data_lcm_t._get_packed_fingerprint():
            raise ValueError("Decode error")
        return hkd_problem_data_lcm_t._decode_one(buf)
    decode = staticmethod(decode)

    def _decode_one(buf):
        self = hkd_problem_data_lcm_t()
        self.n_timesteps = struct.unpack(">i", buf.read(4))[0]
        self.contacts = []
        for i0 in range(4):
            self.contacts.append(struct.unpack('>%df' % self.n_timesteps, buf.read(self.n_timesteps * 4)))
        self.times = struct.unpack('>%df' % self.n_timesteps, buf.read(self.n_timesteps * 4))
        self.pos_r = []
        for i0 in range(3):
            self.pos_r.append(struct.unpack('>%df' % self.n_timesteps, buf.read(self.n_timesteps * 4)))
        self.eul_r = []
        for i0 in range(3):
            self.eul_r.append(struct.unpack('>%df' % self.n_timesteps, buf.read(self.n_timesteps * 4)))
        self.vel_r = []
        for i0 in range(3):
            self.vel_r.append(struct.unpack('>%df' % self.n_timesteps, buf.read(self.n_timesteps * 4)))
        self.omega_r = []
        for i0 in range(3):
            self.omega_r.append(struct.unpack('>%df' % self.n_timesteps, buf.read(self.n_timesteps * 4)))
        self.qdummy_r = []
        for i0 in range(12):
            self.qdummy_r.append(struct.unpack('>%df' % self.n_timesteps, buf.read(self.n_timesteps * 4)))
        self.pos = []
        for i0 in range(3):
            self.pos.append(struct.unpack('>%df' % self.n_timesteps, buf.read(self.n_timesteps * 4)))
        self.eul = []
        for i0 in range(3):
            self.eul.append(struct.unpack('>%df' % self.n_timesteps, buf.read(self.n_timesteps * 4)))
        self.vel = []
        for i0 in range(3):
            self.vel.append(struct.unpack('>%df' % self.n_timesteps, buf.read(self.n_timesteps * 4)))
        self.omega = []
        for i0 in range(3):
            self.omega.append(struct.unpack('>%df' % self.n_timesteps, buf.read(self.n_timesteps * 4)))
        self.qdummy = []
        for i0 in range(12):
            self.qdummy.append(struct.unpack('>%df' % self.n_timesteps, buf.read(self.n_timesteps * 4)))
        return self
    _decode_one = staticmethod(_decode_one)

    _hash = None
    def _get_hash_recursive(parents):
        if hkd_problem_data_lcm_t in parents: return 0
        tmphash = (0xbaab93fbdfb118d) & 0xffffffffffffffff
        tmphash  = (((tmphash<<1)&0xffffffffffffffff) + (tmphash>>63)) & 0xffffffffffffffff
        return tmphash
    _get_hash_recursive = staticmethod(_get_hash_recursive)
    _packed_fingerprint = None

    def _get_packed_fingerprint():
        if hkd_problem_data_lcm_t._packed_fingerprint is None:
            hkd_problem_data_lcm_t._packed_fingerprint = struct.pack(">Q", hkd_problem_data_lcm_t._get_hash_recursive([]))
        return hkd_problem_data_lcm_t._packed_fingerprint
    _get_packed_fingerprint = staticmethod(_get_packed_fingerprint)

