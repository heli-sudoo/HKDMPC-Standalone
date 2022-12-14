"""LCM type definitions
This file automatically generated by lcm.
DO NOT MODIFY BY HAND!!!!
"""

try:
    import cStringIO.StringIO as BytesIO
except ImportError:
    from io import BytesIO
import struct

class hkd_command_lcmt(object):
    __slots__ = ["N_mpcsteps", "mpc_times", "hkd_controls", "des_body_state", "contacts", "statusTimes", "foot_placement", "feedback", "solve_time"]

    __typenames__ = ["int32_t", "double", "float", "float", "int32_t", "double", "float", "float", "float"]

    __dimensions__ = [None, [10], [10, 24], [10, 12], [10, 4], [10, 4], [12], [10, 12, 12], None]

    def __init__(self):
        self.N_mpcsteps = 0
        self.mpc_times = [ 0.0 for dim0 in range(10) ]
        self.hkd_controls = [ [ 0.0 for dim1 in range(24) ] for dim0 in range(10) ]
        self.des_body_state = [ [ 0.0 for dim1 in range(12) ] for dim0 in range(10) ]
        self.contacts = [ [ 0 for dim1 in range(4) ] for dim0 in range(10) ]
        self.statusTimes = [ [ 0.0 for dim1 in range(4) ] for dim0 in range(10) ]
        self.foot_placement = [ 0.0 for dim0 in range(12) ]
        self.feedback = [ [ [ 0.0 for dim2 in range(12) ] for dim1 in range(12) ] for dim0 in range(10) ]
        self.solve_time = 0.0

    def encode(self):
        buf = BytesIO()
        buf.write(hkd_command_lcmt._get_packed_fingerprint())
        self._encode_one(buf)
        return buf.getvalue()

    def _encode_one(self, buf):
        buf.write(struct.pack(">i", self.N_mpcsteps))
        buf.write(struct.pack('>10d', *self.mpc_times[:10]))
        for i0 in range(10):
            buf.write(struct.pack('>24f', *self.hkd_controls[i0][:24]))
        for i0 in range(10):
            buf.write(struct.pack('>12f', *self.des_body_state[i0][:12]))
        for i0 in range(10):
            buf.write(struct.pack('>4i', *self.contacts[i0][:4]))
        for i0 in range(10):
            buf.write(struct.pack('>4d', *self.statusTimes[i0][:4]))
        buf.write(struct.pack('>12f', *self.foot_placement[:12]))
        for i0 in range(10):
            for i1 in range(12):
                buf.write(struct.pack('>12f', *self.feedback[i0][i1][:12]))
        buf.write(struct.pack(">f", self.solve_time))

    def decode(data):
        if hasattr(data, 'read'):
            buf = data
        else:
            buf = BytesIO(data)
        if buf.read(8) != hkd_command_lcmt._get_packed_fingerprint():
            raise ValueError("Decode error")
        return hkd_command_lcmt._decode_one(buf)
    decode = staticmethod(decode)

    def _decode_one(buf):
        self = hkd_command_lcmt()
        self.N_mpcsteps = struct.unpack(">i", buf.read(4))[0]
        self.mpc_times = struct.unpack('>10d', buf.read(80))
        self.hkd_controls = []
        for i0 in range(10):
            self.hkd_controls.append(struct.unpack('>24f', buf.read(96)))
        self.des_body_state = []
        for i0 in range(10):
            self.des_body_state.append(struct.unpack('>12f', buf.read(48)))
        self.contacts = []
        for i0 in range(10):
            self.contacts.append(struct.unpack('>4i', buf.read(16)))
        self.statusTimes = []
        for i0 in range(10):
            self.statusTimes.append(struct.unpack('>4d', buf.read(32)))
        self.foot_placement = struct.unpack('>12f', buf.read(48))
        self.feedback = []
        for i0 in range(10):
            self.feedback.append([])
            for i1 in range(12):
                self.feedback[i0].append(struct.unpack('>12f', buf.read(48)))
        self.solve_time = struct.unpack(">f", buf.read(4))[0]
        return self
    _decode_one = staticmethod(_decode_one)

    _hash = None
    def _get_hash_recursive(parents):
        if hkd_command_lcmt in parents: return 0
        tmphash = (0xd3665dd62ca267b4) & 0xffffffffffffffff
        tmphash  = (((tmphash<<1)&0xffffffffffffffff) + (tmphash>>63)) & 0xffffffffffffffff
        return tmphash
    _get_hash_recursive = staticmethod(_get_hash_recursive)
    _packed_fingerprint = None

    def _get_packed_fingerprint():
        if hkd_command_lcmt._packed_fingerprint is None:
            hkd_command_lcmt._packed_fingerprint = struct.pack(">Q", hkd_command_lcmt._get_hash_recursive([]))
        return hkd_command_lcmt._packed_fingerprint
    _get_packed_fingerprint = staticmethod(_get_packed_fingerprint)

