/* LCM type definition class file
 * This file was automatically generated by lcm-gen
 * DO NOT MODIFY BY HAND!!!!
 */

package lcmtypes;
 
import java.io.*;
import java.util.*;
import lcm.lcm.*;
 
public final class hkd_data_lcmt implements lcm.lcm.LCMEncodable
{
    public double mpctime;
    public int contact[];
    public float p[];
    public float vWorld[];
    public float rpy[];
    public float omegaBody[];
    public float qJ[];
    public float foot_placements[];
 
    public hkd_data_lcmt()
    {
        contact = new int[4];
        p = new float[3];
        vWorld = new float[3];
        rpy = new float[3];
        omegaBody = new float[3];
        qJ = new float[12];
        foot_placements = new float[12];
    }
 
    public static final long LCM_FINGERPRINT;
    public static final long LCM_FINGERPRINT_BASE = 0x84404d6ac9f35f78L;
 
    static {
        LCM_FINGERPRINT = _hashRecursive(new ArrayList<Class<?>>());
    }
 
    public static long _hashRecursive(ArrayList<Class<?>> classes)
    {
        if (classes.contains(lcmtypes.hkd_data_lcmt.class))
            return 0L;
 
        classes.add(lcmtypes.hkd_data_lcmt.class);
        long hash = LCM_FINGERPRINT_BASE
            ;
        classes.remove(classes.size() - 1);
        return (hash<<1) + ((hash>>63)&1);
    }
 
    public void encode(DataOutput outs) throws IOException
    {
        outs.writeLong(LCM_FINGERPRINT);
        _encodeRecursive(outs);
    }
 
    public void _encodeRecursive(DataOutput outs) throws IOException
    {
        outs.writeDouble(this.mpctime); 
 
        for (int a = 0; a < 4; a++) {
            outs.writeInt(this.contact[a]); 
        }
 
        for (int a = 0; a < 3; a++) {
            outs.writeFloat(this.p[a]); 
        }
 
        for (int a = 0; a < 3; a++) {
            outs.writeFloat(this.vWorld[a]); 
        }
 
        for (int a = 0; a < 3; a++) {
            outs.writeFloat(this.rpy[a]); 
        }
 
        for (int a = 0; a < 3; a++) {
            outs.writeFloat(this.omegaBody[a]); 
        }
 
        for (int a = 0; a < 12; a++) {
            outs.writeFloat(this.qJ[a]); 
        }
 
        for (int a = 0; a < 12; a++) {
            outs.writeFloat(this.foot_placements[a]); 
        }
 
    }
 
    public hkd_data_lcmt(byte[] data) throws IOException
    {
        this(new LCMDataInputStream(data));
    }
 
    public hkd_data_lcmt(DataInput ins) throws IOException
    {
        if (ins.readLong() != LCM_FINGERPRINT)
            throw new IOException("LCM Decode error: bad fingerprint");
 
        _decodeRecursive(ins);
    }
 
    public static lcmtypes.hkd_data_lcmt _decodeRecursiveFactory(DataInput ins) throws IOException
    {
        lcmtypes.hkd_data_lcmt o = new lcmtypes.hkd_data_lcmt();
        o._decodeRecursive(ins);
        return o;
    }
 
    public void _decodeRecursive(DataInput ins) throws IOException
    {
        this.mpctime = ins.readDouble();
 
        this.contact = new int[(int) 4];
        for (int a = 0; a < 4; a++) {
            this.contact[a] = ins.readInt();
        }
 
        this.p = new float[(int) 3];
        for (int a = 0; a < 3; a++) {
            this.p[a] = ins.readFloat();
        }
 
        this.vWorld = new float[(int) 3];
        for (int a = 0; a < 3; a++) {
            this.vWorld[a] = ins.readFloat();
        }
 
        this.rpy = new float[(int) 3];
        for (int a = 0; a < 3; a++) {
            this.rpy[a] = ins.readFloat();
        }
 
        this.omegaBody = new float[(int) 3];
        for (int a = 0; a < 3; a++) {
            this.omegaBody[a] = ins.readFloat();
        }
 
        this.qJ = new float[(int) 12];
        for (int a = 0; a < 12; a++) {
            this.qJ[a] = ins.readFloat();
        }
 
        this.foot_placements = new float[(int) 12];
        for (int a = 0; a < 12; a++) {
            this.foot_placements[a] = ins.readFloat();
        }
 
    }
 
    public lcmtypes.hkd_data_lcmt copy()
    {
        lcmtypes.hkd_data_lcmt outobj = new lcmtypes.hkd_data_lcmt();
        outobj.mpctime = this.mpctime;
 
        outobj.contact = new int[(int) 4];
        System.arraycopy(this.contact, 0, outobj.contact, 0, 4); 
        outobj.p = new float[(int) 3];
        System.arraycopy(this.p, 0, outobj.p, 0, 3); 
        outobj.vWorld = new float[(int) 3];
        System.arraycopy(this.vWorld, 0, outobj.vWorld, 0, 3); 
        outobj.rpy = new float[(int) 3];
        System.arraycopy(this.rpy, 0, outobj.rpy, 0, 3); 
        outobj.omegaBody = new float[(int) 3];
        System.arraycopy(this.omegaBody, 0, outobj.omegaBody, 0, 3); 
        outobj.qJ = new float[(int) 12];
        System.arraycopy(this.qJ, 0, outobj.qJ, 0, 12); 
        outobj.foot_placements = new float[(int) 12];
        System.arraycopy(this.foot_placements, 0, outobj.foot_placements, 0, 12); 
        return outobj;
    }
 
}
